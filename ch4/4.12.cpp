/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    int PathsWithSum(TreeNode* root, int sum) {
        if (!root) return 0;
        int ret = 0;
        unordered_map<int, int> pathSumCount;
        pathSumCount[0] = 1;
        backtrack(ret, pathSumCount, 0, root, sum);
        return ret;
    }
private:
    void backtrack(int& ret, unordered_map<int, int>& pathSumCount, int pathSum, TreeNode* node, int sum) {
        pathSum += node->val;
        if (pathSumCount.count(pathSum - sum)) ret += pathSumCount[pathSum - sum];
        
        pathSumCount[pathSum]++;

        if (node->left) {
            backtrack(ret, pathSumCount, pathSum, node->left, sum);
        }
        if (node->right) {
            backtrack(ret, pathSumCount, pathSum, node->right, sum);
        }
        pathSumCount[pathSum]--;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line1, line2;
    while (getline(cin, line1)) {
        getline(cin, line2);
        istringstream iss1(line1);
        TreeNode* root = TreeNode::Read(iss1);
        int sum = atoi(line2.c_str());
        cout << sol.PathsWithSum(root, sum) << endl;
    }

    return 0;
}
