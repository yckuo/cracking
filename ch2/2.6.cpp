/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    bool IsPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        stack<int> stk;
        bool odd = false;
        ListNode *slow = head, *fast = head->next;
        stk.push(slow->val);
        while (fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (!fast) {
                odd = true;
                break;
            }

            stk.push(slow->val);
        }

        while (slow->next) {
            slow = slow->next;
            int val = stk.top();
            stk.pop();
            if (val != slow->val) return false;
        }

        return true;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        ListNode *head = ListNode::Read(iss);
        if (sol.IsPalindrome(head)) cout << "True:  ";
        else cout << "False: ";
        head->Print();
        cout << endl;
    }
    return 0;
}
