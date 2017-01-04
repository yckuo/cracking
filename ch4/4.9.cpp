/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_set>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    vector<vector<int>> AllSequences(TreeNode* root) {
        vector<vector<int>> ret;
        if (!root) return ret;

        vector<int> cur;
        unordered_set<TreeNode*> options = { root };
        backtrack(ret, cur, options);
        return ret;
    }

private:
    void backtrack(vector<vector<int>>& ret, vector<int>& cur, unordered_set<TreeNode*> options) {
        if (options.empty()) {
            ret.push_back(cur);
            return;
        }

        unordered_set<TreeNode*> nextOptions = options;

        for (TreeNode* option : options) {
            nextOptions.erase(option);
            if (option->left) nextOptions.insert(option->left);
            if (option->right) nextOptions.insert(option->right);
            cur.push_back(option->val);

            backtrack(ret, cur, nextOptions);
            
            nextOptions.insert(option);
            if (option->left) nextOptions.erase(option->left);
            if (option->right) nextOptions.erase(option->right);
            cur.pop_back();
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        TreeNode *root = TreeNode::Read(iss);
        vector<vector<int>> ans = sol.AllSequences(root);
        for (vector<int> seq : ans) {
            for (int num : seq) {
                cout << num << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}
