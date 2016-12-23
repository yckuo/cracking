#include <iostream>
#include <fstream>
#include <sstream>
#include "ListNode.h"
using namespace std;

class Solution {
public:
    ListNode* Sum(ListNode* num1, ListNode* num2) {
        int len1 = this->GetLen(num1), len2 = this->GetLen(num2);
        if (len1 > len2) num2 = this->PadZero(num2, len1 - len2);
        else if (len2 > len1) num1 = this->PadZero(num1, len2 - len1);
        
        ListNode* ret;
        P p = helper(num1, num2);
        if (p.first > 0) {
            ret = new ListNode(p.first%10);
            ret->next = p.second;
        } else {
            ret = p.second;
        }

        return ret;
    }

private:
    typedef pair<int, ListNode*> P;

    P helper(ListNode* node1, ListNode *node2) {
        int sum = node1->val + node2->val;
        ListNode *next = NULL;
        if (node1->next && node2->next) {
            P tmp = helper(node1->next, node2->next);
            sum += tmp.first;
            next = tmp.second;
        }

        ListNode* ret = new ListNode(sum % 10);
        ret->next = next;
        return {sum / 10, ret};
    }

    int GetLen(ListNode* head) {
        int ret = 0;
        while (head) {
            ret++;
            head = head->next;
        }
        return ret;
    }

    ListNode* PadZero(ListNode *head, int count) {
        for (int i=0; i<count; i++) {
            ListNode *tmp = new ListNode(0);
            tmp->next = head;
            head = tmp;
        }
        return head;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line, line2;
    while (getline(cin, line)) {
        getline(cin, line2);
        istringstream iss(line), iss2(line2);
        ListNode* head1 = ListNode::Read(iss);
        ListNode* head2 = ListNode::Read(iss2);
        ListNode* sum = sol.Sum(head1, head2);
        head1->Print();
        head2->Print();
        sum->Print();
        cout << endl;
    }

    return 0;
}
