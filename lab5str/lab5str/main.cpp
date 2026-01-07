#include "TreeNew.h"

int main() {
    setlocale(0, "");

    TreeNode* root = nullptr;
    std::string filename = "test1.txt";

    createFromFile(root, filename);

    if (isEmpty(root)) {
        std::cout << "Дерево пустое." << std::endl;
        return 0;
    }

    std::cout << "\nДерево:\n";
    output(root);
    std::cout << std::endl;

    int maxSum = INT_MIN;
    findMaxSum(root, 0, maxSum);

    if (maxSum == INT_MIN) maxSum = root->data;
    std::cout << "\nПути с максимальной суммой (" << maxSum << "):\n";

    int path[MAX_DEEP];
    printPaths(root, path, 0, 0, maxSum);

    clear(root);
    return 0;
}
//10 2 8 9 4 1 3 5 7 11 3 2 5 2 7