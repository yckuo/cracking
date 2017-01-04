/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>
#include "TreeNode.h"
using namespace std;

class Solution {
public:
    /*
    // Problem 1: root not given; parent links are available from all tree nodes. Only constant space is allowed.
    TreeNode* FirstCommonAncestor(TreeNode* node1, TreeNode* node2) {
        // It's possible that these 2 nodes do not belong to the same tree.
        TreeNode *p1 = node1, *p2 = node2;
        int c1 = 1, c2 = 1;
        while (p1->parent != NULL) {
            p1 = p1->parent;
            ++c1;
        }
        while (p2->parent != NULL) {
            p2 = p2->parent;
            ++c2;
        }
        if (p1 != p2) return NULL;
        p1 = node1;
        p2 = node2;
        if (c1 > c2) {
            for (int i=0; i < c1-c2; i++) p1 = p1->parent;
        } else if (c2 > c1) {
            for (int i=0; i < c2-c1; i++) p2 = p2->parent;
        }

        while (p1 != p2) {
            p1 = p1->parent;
            p2 = p2->parent;
        }

        return p1;
    }

    // Problem 2: root not given; parent links are available from all tree nodes. Non-constant extra space is allowed.
    TreeNode* FirstCommonAncestor(TreeNode* node1, TreeNode* node2) {
        // It's possible that these 2 nodes do not belong to the same tree.
        unordered_set<TreeNode*> path;
        while (node1) {
            path.insert(node1);
            node1 = node1->parent;
        }

        while (node2) {
            if (path.count(node2)) return node2;
            node2 = node2->parent;
        }
    }
    */

    // Problem 3: root given; no parent links
    // This function returns LCA if root is an ancestor of both node1 and node2
    // If root is the ancestor of only one of the two nodes, return that node.
    // Otherwise return NULL
    TreeNode* FirstCommonAncestor(TreeNode* node1, TreeNode* node2, TreeNode* root) {
        // Important: if either node1 or node2 is not a descendent of root, then return NULL.
        if (!Find(root, node1)) return NULL;
        if (!Find(root, node2)) return NULL;

        return helper(node1, node2, root);
    }

private:
    TreeNode* helper(TreeNode* node1, TreeNode* node2, TreeNode* root) {
        if (!root) return NULL;
        if (root == node1 || root == node2) return root;
        TreeNode* left = helper(node1, node2, root->left);
        TreeNode* right = helper(node1, node2, root->right);
        if (!left) return right;
        if (!right) return left;
        return root;
    }

    bool Find(TreeNode* root, TreeNode* node) {
        if (!root) return false;
        if (root == node) return true;
        if (Find(root->left, node)) return true;
        if (Find(root->right, node)) return true;
        return false;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line1, line2;
    while (getline(cin, line1)) {
        getline(cin, line2);
        istringstream iss1(line1), iss2(line2);
        TreeNode* root = TreeNode::Read(iss1);
        int v1, v2;
        iss2 >> v1 >> v2;
        TreeNode *node1 = root->Search(v1), *node2 = root->Search(v2);
        TreeNode *ans = sol.FirstCommonAncestor(node1, node2, root);
        if (!ans) cout << "INVALID" << endl;
        else cout << ans->val << endl;
    }

    return 0;
}
