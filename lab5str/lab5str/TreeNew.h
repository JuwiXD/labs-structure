#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <climits>

const int MAX_DEEP = 100;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(nullptr), right(nullptr), data(0) {}
    TreeNode(int elem) : data(elem), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int elem);
bool searchRec(TreeNode* root, int elem);
bool search(TreeNode* root, int elem);
bool isEmpty(TreeNode* root);
void clear(TreeNode*& root);
void output(TreeNode* root, int space = 0, int indent = 4);
void createFromFile(TreeNode*& root, const std::string& filename);
void findMaxSum(TreeNode* node, int currentSum, int& maxSum);
void printPaths(TreeNode* node, int path[], int pathLen, int currentSum, int targetSum);