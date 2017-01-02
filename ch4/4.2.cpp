/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    TreeNode* MinimalTree(vector<int>& sorted) {
        if (sorted.empty()) return NULL;
        int N = sorted.size();
        return MinimalTree(sorted, 0, N-1);
    }
private:
    TreeNode* MinimalTree(vector<int>& sorted, int lo, int hi) {
        if (lo > hi) return NULL;
        int mid = lo + (hi - lo + 1) / 2;
        TreeNode *root = new TreeNode(sorted[mid]);
        root->left = MinimalTree(sorted, lo, mid-1);
        root->right = MinimalTree(sorted, mid+1, hi);
        return root;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        int val;
        vector<int> sorted;
        while (iss >> val) {
            sorted.push_back(val);
        }
        TreeNode* ans = sol.MinimalTree(sorted);
        if (!ans) cout << "#";
        else ans->Print();
        
        cout << endl;
    }

    return 0;
}
