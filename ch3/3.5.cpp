/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

class Solution {
public:
    void SortStack(stack<int>& stk) {
        stack<int> tmp;
        while (!stk.empty()) {
            int val = stk.top();
            stk.pop();
            while (!tmp.empty() && tmp.top() > val) {
                stk.push(tmp.top());
                tmp.pop();
            }
            tmp.push(val);
        }

        while (!tmp.empty()) {
            stk.push(tmp.top());
            tmp.pop();
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;

    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        stack<int> stk;
        int val;
        while (iss >> val) {
            stk.push(val);
        }
        sol.SortStack(stk);
        while (!stk.empty()) {
            cout << stk.top() << " ";
            stk.pop();
        }
        cout << endl;
    }

    return 0;
}
