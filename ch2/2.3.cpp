/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include "ListNode.h"
using namespace std;

class Solution {
    public:
    void Delete(ListNode* node) {
        if (!node || !node->next) return;

        while (node->next->next) {
            node->val = node->next->val;
            node = node->next;
        }
        node->val = node->next->val;
        delete node->next;
        node->next = NULL;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);

    int N;
    cin >> N;
    ListNode* head = ListNode::Read(cin, N);
    head->Print();

    Solution sol;
    int k;
    while(cin >> k) {
        ListNode *copy = head->Copy(), *toDelete = copy;
        for (int i=1; i<k && toDelete; i++) {
            toDelete = toDelete->next;
        }
        sol.Delete(toDelete);
        cout << k << ": ";
        copy->Print();
    }

    return 0;
}
