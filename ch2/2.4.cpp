/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode *Partition(ListNode *head, int pivot) {
        ListNode *left = new ListNode(0), *right = new ListNode(0), *l = left, *r = right;
        ListNode *node = head;
        while (node) {
            if (node->val < pivot) {
                l->next = node;
                l = l->next;
            } else {
                r->next = node;
                r = r->next;
            }
            node = node->next;
        }
        l->next = right->next;
        r->next = NULL;
        l = left->next;
        r = right->next;
        delete left;
        delete right;
        return l;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int N;
    cin >> N;
    ListNode *head = ListNode::Read(cin, N);
    head->Print();
    int pivot;
    while (cin >> pivot) {
        ListNode *copy = head->Copy();
        copy = sol.Partition(copy, pivot);
        cout << pivot << ": ";
        copy->Print();
    }

    return 0;
}
