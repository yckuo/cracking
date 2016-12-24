/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

class MyQueue {
public:
    void Push(int x) {
        stk1.push(x);
    }

    int Front() {
        if (stk1.empty()) return 0; // throw an empty stack exception
        Dump(stk1, stk2);
        int ret = stk2.top();
        Dump(stk2, stk1);
        return ret;
    }

    void Pop() {
        if (stk1.empty()) return; // throw an empty stack exception
        Dump(stk1, stk2);
        stk2.pop();
        Dump(stk2, stk1);
    }

private:
    stack<int> stk1, stk2;

    void Dump(stack<int>& x, stack<int>& y) {
        while (!x.empty()) {
            y.push(x.top());
            x.pop();
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    string line;
    while (getline(cin, line)) {
        MyQueue q;
        istringstream iss(line);
        string token;
        while (iss >> token) {
            if (token == "pop") {
                q.Pop();
                cout << "popped, ";
            } else if (token == "front") {
                cout << q.Front() << ", ";
            } else {
                int val = atoi(token.c_str());
                q.Push(val);
                cout << "pushed " << val << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}
