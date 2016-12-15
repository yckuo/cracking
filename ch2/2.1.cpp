/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <unordered_set>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    void RemoveDups1(ListNode* head) {
        unordered_set<int> seen;
        for (ListNode *node = head; node; node = node->next) {
            seen.insert(node->val);
            while (node->next && seen.count(node->next->val)) {
                ListNode *next = node->next->next;
                delete node->next;
                node->next = next;
            }
        }
    }

    void RemoveDups2(ListNode* head) {
        for (ListNode *node = head; node; node = node->next) {
            for (ListNode *check = node; check->next;) {
                if (check->next->val == node->val) {
                    ListNode* next = check->next->next;
                    delete check->next;
                    check->next = next;
                } else {
                    check = check->next;
                }
            }
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;

    ListNode *head = ListNode::Read(cin);
    head->Print();

    sol.RemoveDups2(head);

    head->Print();

    return 0;
}
