/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <climits>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool IsBST(TreeNode* root) {
        return IsBST(root, INT_MIN, INT_MAX);
    }

private:
    bool IsBST(TreeNode* root, int minval, int maxval) {
        if (!root) return true;
        return root->val <= maxval && root->val >= minval && IsBST(root->left, minval, root->val - 1) && IsBST(root->right, root->val + 1, maxval);
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        TreeNode* root = TreeNode::Read(iss);
        cout << sol.IsBST(root) << endl;
    }

    return 0;
}
