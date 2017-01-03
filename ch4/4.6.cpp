/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* Successor(TreeNode* node, stack<TreeNode*> parents) {
        if (!node) return NULL;
        if (node->right) {
            TreeNode *ret = node->right;
            while (ret->left) ret = ret->left;
            return ret;
        } else {
            while (!parents.empty() && node == parents.top()->right) {
                node = parents.top();
                parents.pop();
            }
            if (parents.empty()) return NULL;
            return parents.top();
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line, target;
    while (getline(cin, line)) {
        getline(cin, target);
        istringstream iss(line);
        TreeNode* root = TreeNode::Read(iss);
        int val = atoi(target.c_str());
        stack<TreeNode*> parents;

        parents.push(root);
        while (!parents.empty()) {
            TreeNode* cur = parents.top();
            parents.pop();
            if (val == cur->val) { // found it
                TreeNode* next = sol.Successor(cur, parents);
                if (!next) cout << "NULL" << endl;
                else cout << next->val << endl;
                break;
            } else if (val > cur->val) {
                parents.push(cur);
                if (!cur->right) {
                    cout << "NULL" << endl;
                    break;
                }
                parents.push(cur->right);
            } else {
                parents.push(cur);
                if (!cur->left) {
                    cout << "NULL" << endl;
                    break;
                }
                parents.push(cur->left);
            }
        }
    }

    return 0;
}
