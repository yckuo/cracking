/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include "ListNode.h"
using namespace std;

ListNode::ListNode(int val) : val(val), next(NULL) {
}

void ListNode::Print() {
    cout << this->val << " ";
    if (this->next == NULL) cout << endl;
    else this->next->Print();
}

ListNode* ListNode::Copy() {
    ListNode *node = new ListNode(this->val);
    if (this->next) node->next = this->next->Copy();
    return node;
}

ListNode* ListNode::Read(istream& stream) {
    int val;
    ListNode *dummy = new ListNode(0), *p = dummy;
    while (stream >> val) {
        p->next = new ListNode(val);
        p = p->next;
    }

    p = dummy->next;
    delete dummy;
    return p;
}

ListNode* ListNode::Read(istream& stream, int N) {
    int val;
    ListNode *dummy = new ListNode(0), *p = dummy;
    for (int i=0; i<N; i++) {
        stream >> val;
        p->next = new ListNode(val);
        p = p->next;
    }

    p = dummy->next;
    delete dummy;
    return p;
}
