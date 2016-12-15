/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include "ListNode.h"
using namespace std;

typedef pair<ListNode*, int> P;

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

    // Recursive solution
    P KthToLast2(ListNode* head, int k) {
        if (!head) return {NULL, 0};
        P p = KthToLast2(head->next, k);
        int count = 1 + p.second;
        if (p.first) return {p.first, count};
        if (count == k) return {head, count};
        return {NULL, count};
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
        // ListNode *node = sol.KthToLast(head, k);
        P p = sol.KthToLast2(head, k);
        ListNode *node = p.first;
        cout << k << ": ";
        if (!node) cout << "NULL" << endl;
        else cout << node->val << endl;
    }
    return 0;
}
