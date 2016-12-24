/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

class MyQueue {
public:
    MyQueue() : in2(false) {}

    void Push(int x) {
        if (in2) {
            Dump(stk2, stk1);
            in2 = false;
        }
        stk1.push(x);
    }

    int Front() {
        if (!in2 && stk1.empty() || in2 && stk2.empty()) return 0; // throw an empty stack exception
        
        if (!in2) {
            Dump(stk1, stk2);
            in2 = true;
        }
        int ret = stk2.top();
        return ret;
    }

    void Pop() {
        if (!in2 && stk1.empty() || in2 && stk2.empty()) return; // throw an empty stack exception
        
        if (!in2) {
            Dump(stk1, stk2);
            in2 = true;
        }
        stk2.pop();
    }

private:
    stack<int> stk1, stk2;
    bool in2;

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
