/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* FindIntersection(ListNode *list1, ListNode *list2) {
        ListNode *p1 = list1, *p2 = list2;
        bool s1 = false, s2 = false;
        while (true) {
            if (!p1 && !p2) return NULL;
            if (p1 == p2) return p1;

            if (!p1) {
                if (s1) return NULL;
                s1 = true;
                p1 = list2;
            } else {
                p1 = p1->next;
            }
            if (!p2) {
                if (s2) return NULL;
                s2 = true;
                p2 = list1;
            } else {
                p2 = p2->next;
            }
        }

        return NULL;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line1, line2, line3;
    while (getline(cin, line1)) {
        getline(cin, line2);
        getline(cin, line3);
        istringstream iss1(line1), iss2(line2), iss3(line3);
        ListNode *l1 = ListNode::Read(iss1), *l2 = ListNode::Read(iss2), *l3 = ListNode::Read(iss3);
        if (!l1) l1 = l3;
        else {
            ListNode *p1 = l1;
            while (p1->next) p1 = p1->next;
            p1->next = l3;
        }
        if (!l2) l2 = l3;
        else {
            ListNode *p2 = l2;
            while (p2->next) p2 = p2->next;
            p2->next = l3;
        }

        ListNode *ans = sol.FindIntersection(l1, l2);
        if (ans) cout << ans->val << endl;
        else cout << "NULL" << endl;
    }

    return 0;
}

