/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* LoopStart(ListNode* head) {
        if (!head || !head->next) return NULL;
        ListNode *slow = head, *fast = head->next;
        while (slow != fast && fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        if (!fast || !fast->next) return NULL;
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        slow = dummy;
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;

    string line;
    while (getline(cin, line)) {

        istringstream iss(line);
        ListNode *head = ListNode::Read(iss);

        getline(cin, line);
        int N = atoi(line.c_str());
        if (N != 0) {
            ListNode *back = head, *tail = head;
            for (int i=1; i<N; i++) back = back->next;
            while (tail->next) tail = tail->next;
            tail->next = back;
        }

        ListNode* ans = sol.LoopStart(head);
        if (ans) cout << ans->val << endl;
        else cout << "NULL" << endl;
    }

    return 0;
}
