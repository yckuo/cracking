/* Copyright (C) yckuo - All Rights Reserved */

#include <fstream>
#include <stack>
#include <unordered_set>
#include "TreeNode.h"
using namespace std;

TreeNode::TreeNode(int val) : val(val), left(NULL), right(NULL) {
}

void TreeNode::Print() {
    cout << val << " ";
    if (left) {
        left->Print();
    } else {
        cout << "# ";
    }

    if (right) {
        right->Print();
    } else {
        cout << "# ";
    }
}

TreeNode* TreeNode::Read(istream& stream) {
    TreeNode* ret = NULL;
    stack<TreeNode*> parents;
    unordered_set<TreeNode*> leftPopulated;
    string token;
    while (stream >> token) {
        if (token == "#") {
            if (parents.empty()) return NULL;
            TreeNode* parent = parents.top();
            if (leftPopulated.count(parent)) {
                parents.pop();
            } else {
                leftPopulated.insert(parent);
            }
        } else {
            int val = atoi(token.c_str());
            if (parents.empty()) {
                ret = new TreeNode(val);
                parents.push(ret);
            } else {
                TreeNode* parent = parents.top();
                if (leftPopulated.count(parent)) {
                    parent->right = new TreeNode(val);
                    parents.pop();
                    parents.push(parent->right);
                } else {
                    parent->left = new TreeNode(val);
                    leftPopulated.insert(parent);
                    parents.push(parent->left);
                }
            }
        }
    }
    return ret;
}

TreeNode* TreeNode::Search(int val) {
    if (this->val == val) return this;
    if (this->left) {
        TreeNode* l = this->left->Search(val);
        if (l) return l;
    }
    if (this->right) {
        TreeNode* r = this->right->Search(val);
        if (r) return r;
    }
    return NULL;
}
