/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    bool IsBalanced(TreeNode* root) {
        unordered_map<TreeNode*, int> mem; // memoization for the height of child trees
        mem[NULL] = 0;
        return -1 != height(root, mem);
    }
private:
    int height(TreeNode* root, unordered_map<TreeNode*, int>& mem) {
        if (mem.count(root)) return mem[root];
        if (!root->left && !root->right) return mem[root] = 1;

        int lh = 0, rh = 0;
        if (root->left) lh = height(root->left, mem);
        if (root->right) rh = height(root->right, mem);
        if (lh == -1 || rh == -1) return -1; // unbalanced
        if (lh - rh > 1 || rh - lh > 1) return -1; // unbalanced
        return 1 + max(lh, rh);
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        TreeNode* root = TreeNode::Read(iss);
        cout << sol.IsBalanced(root) << endl;
    }

    return 0;
}
