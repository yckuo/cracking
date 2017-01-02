/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include "TreeNode.h"
using namespace std;

TreeNode::TreeNode(int val) : val(val) {
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
