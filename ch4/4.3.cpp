/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>
#include <queue>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<list<TreeNode*>> ListOfDepths(TreeNode *root) {
        vector<list<TreeNode*>> ret;
        if (!root) return ret;
        
        // Breadth-First Traversal
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, int> depth;
        depth[root] = 0;

        list<TreeNode*> l;
        while (!q.empty()) {
            TreeNode *cur = q.front();
            q.pop();
            int d = depth[cur];
            if (d > ret.size()) {
                ret.push_back(l);
                l.clear();
            }

            l.push_back(cur);

            if (cur->left) {
                q.push(cur->left);
                depth[cur->left] = d + 1;
            }
            if (cur->right) {
                q.push(cur->right);
                depth[cur->right] = d + 1;
            }
        }
        ret.push_back(l);
        return ret;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        TreeNode *root = TreeNode::Read(iss);
        vector<list<TreeNode*>> ans = sol.ListOfDepths(root);
        for (list<TreeNode*> l : ans) {
            for (TreeNode* node : l) cout << node->val << " ";
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
