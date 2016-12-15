/* Copyright (C) yckuo - All Rights Reserved */

#pragma once

#include <iostream>
using namespace std;

class ListNode {
public:
    ListNode(int val);
    void Print();
    ListNode* Copy();
    static ListNode* Read(istream& stream);
    static ListNode* Read(istream& stream, int N);

    int val;
    ListNode *next;
};
