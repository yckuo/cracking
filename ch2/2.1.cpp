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
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;

    ListNode *head = ListNode::Read(cin);
    head->Print();

    sol.RemoveDups1(head);

    head->Print();

    return 0;
}
