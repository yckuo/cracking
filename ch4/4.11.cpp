/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
using namespace std;

class RandomBinaryTreeNode {
public:
    RandomBinaryTreeNode(int val) : val(val), count(1), left(NULL), right(NULL) {
    }
    int val, count;
    RandomBinaryTreeNode *left, *right;
};

class RandomBinaryTree {
public:
    RandomBinaryTree() : root(NULL) {
        srand(time(NULL));
    }

    void Insert(int val) {
        if (!root) root = new RandomBinaryTreeNode(val);
        else {
            RandomBinaryTreeNode *node = root;
            while (node) {
                node->count++;
                if (node->val >= val) {
                    if (node->left) {
                        node = node->left;
                    } else {
                        node->left = new RandomBinaryTreeNode(val);
                        break;
                    }
                } else {
                    if (node->right) {
                        node = node->right;
                    } else {
                        node->right = new RandomBinaryTreeNode(val);
                        break;
                    }
                }
            }
        }
    }

    RandomBinaryTreeNode* Find(int val) {
        if (!root) return NULL;
        RandomBinaryTreeNode *node = root;
        while (node) {
            if (val == node->val) return node;
            if (val > node->val) node = node->right;
            else node = node->left;
        }
        return NULL;
    }

    RandomBinaryTreeNode* GetRandomNode() {
        if (!root) return NULL;
        int n = rand() % root->count;
        return helper(root, n);
    }

private:
    RandomBinaryTreeNode* helper(RandomBinaryTreeNode* node, int n) {
        int lsize = node->left ? node->left->count : 0;
        if (n == lsize) {
            return node;
        } else if (n >= 0 && n <= lsize - 1) {
            return helper(node->left, n);
        } else {
            return helper(node->right, n - 1 - lsize);
        }
    }

    RandomBinaryTreeNode *root;
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    string line;
    while (getline(cin, line)) {
        RandomBinaryTree tree;
        istringstream iss(line);
        int val;
        while (iss >> val) {
            tree.Insert(val);
            RandomBinaryTreeNode *r = tree.GetRandomNode();
            if (!r) cout << "NULL ";
            else cout << r->val << " ";
        }
        cout << endl;
    }

    return 0;
}
