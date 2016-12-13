 /* Copyright (C) yckuo - All Rights Reserved */

#pragma once

#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode(int val);
    void Print();
    static ListNode* Read(istream& stream);

    int val;
    ListNode *next;
};
