/* Copyright (C) yckuo - All Rights Reserved */

#pragma once

#include <iostream>
using namespace std;

class TreeNode {
public:
    TreeNode(int val);
    void Print();
    static TreeNode* Read(istream& stream);

    int val;
    TreeNode *left, *right;
};
