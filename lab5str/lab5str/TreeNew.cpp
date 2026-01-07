#include "TreeNew.h"
#include <iostream>
#include <fstream>
#include <queue>

void insert(TreeNode*& root, int elem) {
    TreeNode* newNode = new TreeNode(elem);
    if (root == nullptr) {
        root = newNode;
        return;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* current = q.front(); 
        q.pop();
        if (current->left == nullptr) {
            current->left = newNode;
            return;
        }
        else {
            q.push(current->left);
        }
        if (current->right == nullptr) {
            current->right = newNode;
            return;
        }
        else {
            q.push(current->right);
        }
    }
}

bool searchRec(TreeNode* root, int elem) {
    if (!root) return false;
    if (root->data == elem) return true;
    return searchRec(root->left, elem) || searchRec(root->right, elem);
}

bool search(TreeNode* root, int elem) {
    if (!root) return false;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* cur = q.front(); q.pop();
        if (cur->data == elem) return true;
        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);
    }
    return false;
}

bool isEmpty(TreeNode* root) { return root == nullptr; }

void clear(TreeNode*& root) {
    if (root) {
        clear(root->left);
        clear(root->right);
        delete root;
        root = nullptr;
    }
}

void output(TreeNode* root, int space, int indent) {
    if (!root) {
        if (space == 0) std::cout << "Дерево пустое" << std::endl;
        return;
    }
    space += indent;
    output(root->right, space, indent);
    std::cout << std::endl;
    for (int i = indent; i < space; i++) std::cout << " ";
    std::cout << root->data;
    output(root->left, space, indent);
}

void createFromFile(TreeNode*& root, const std::string& filename) {
    std::ifstream input(filename);
    if (!input.is_open()) {
        std::cout << "Файл не открыт: " << filename << std::endl;
        return;
    }
    int value;
    while (input >> value) {
        insert(root, value);
    }
    input.close();
}

void findMaxSum(TreeNode* node, int currentSum, int& maxSum) {
    if (!node) return;
    currentSum += node->data;
    if (!node->left && !node->right) {
        if (currentSum > maxSum) maxSum = currentSum;
        return;
    }
    findMaxSum(node->left, currentSum, maxSum);
    findMaxSum(node->right, currentSum, maxSum);
}

void printPaths(TreeNode* node, int path[], int pathLen, int currentSum, int targetSum) {
    if (!node) return;
    path[pathLen] = node->data;
    pathLen++;
    currentSum += node->data;

    if (!node->left && !node->right) {
        if (currentSum == targetSum) {
            for (int i = 0; i < pathLen; i++) {
                std::cout << path[i];
                if (i < pathLen - 1) std::cout << " -> ";
            }
            std::cout << " (сумма = " << currentSum << ")" << std::endl;
        }
    }
    else {
        printPaths(node->left, path, pathLen, currentSum, targetSum);
        printPaths(node->right, path, pathLen, currentSum, targetSum);
    }
}