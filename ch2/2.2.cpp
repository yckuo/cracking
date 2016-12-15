/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* KthToLast(ListNode* head, int k) {
        if (k <= 0) return NULL;
        ListNode *fast = head, *slow = head;
        for (int i=0; i<k; i++) {
            if (!fast) return NULL;
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    int n;
    cin >> n;
    ListNode* head = ListNode::Read(cin, n);
    head->Print();
    
    Solution sol;
    int k;
    while (cin >> k) {
        ListNode *node = sol.KthToLast(head, k);
        cout << k << ": ";
        if (!node) cout << "NULL" << endl;
        else cout << node->val << endl;
    }
    return 0;
}
