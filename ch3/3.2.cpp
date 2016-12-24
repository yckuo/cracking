/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
using namespace std;

class MinStack {
public:
    int Top() {
        if (stk.empty()) {
            return 0;
            // throw an empty stack exception
        }
        return stk.top();
    }

    int Min() {
        if (minstk.empty()) {
            return 0;
            // throw an empty stack exception
        }
        return minstk.top();
    }
    
    void Pop() {
        if (stk.empty()) {
            return;
            // or throw an empty stack exception
        }
        if (stk.top() == minstk.top()) minstk.pop();
        stk.pop();
    }
    
    void Push(int x) {
        stk.push(x);
        if (minstk.empty() || minstk.top() >= x) minstk.push(x);
    }

private:
    stack<int> stk;
    stack<int> minstk;
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    string line;
    while (getline(cin, line)) {
        MinStack minStack;
        string token;
        istringstream iss(line);
        while (getline(iss, token, ' ')) {
            if (token == "min") {
                cout << minStack.Min() << " ";
            } else if (token == "pop") {
                minStack.Pop();
                cout << "popped ";
            } else if (token == "top") {
                cout << minStack.Top() << " ";
            } else {
                int val = atoi(token.c_str());
                minStack.Push(val);
                cout << "pushed ";
            }
        }
        cout << endl;
    }

    return 0;
}
