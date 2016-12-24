/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stack>
#include <vector>
using namespace std;

class SetOfStacks {
public:
    SetOfStacks(int capacity) : capacity(capacity), cur(0) {
        stacks.resize(1);
    }

    void Push(int x) {
        if (stacks[cur].size() >= capacity) {
            if (++cur >= stacks.size()) stacks.push_back(stack<int>());
        }
        stacks[cur].push(x);
    }

    void Pop() {
        Shift();
        if (stacks[cur].empty()) return; // throw an empty stack exception
        stacks[cur].pop();
        Shift();
    }

    int Top() {
        if (stacks[cur].empty()) return 0; // throw an empty stack exception
        return stacks[cur].top();
    }

    void PopAt(int idx) {
        if (stacks[idx].empty()) return; // throw an empty stack exception
        stacks[idx].pop();
    }

private:
    void Shift() {
        while (cur > 0 && stacks[cur].empty()) cur--;
    }
    int capacity, cur;
    vector<stack<int>> stacks;
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    string line;
    while (getline(cin, line)) {
        int capacity = atoi(line.c_str());
        SetOfStacks stk(capacity);
        getline(cin, line);

        istringstream iss(line);
        string token;
        bool popat = false;

        while (getline(iss, token, ' ')) {
            if (token == "pop") {
                stk.Pop();
                cout << "popped, ";
            } else if (token == "popat") {
                popat = true;
            } else if (token == "top") {
                cout << stk.Top() << ", ";
            } else {
                int val = atoi(token.c_str());
                if (popat) {
                    stk.PopAt(val);
                    cout << "popped at " << val << ", ";
                    popat = false;
                } else {
                    stk.Push(val);
                    cout << "pushed " << val << ", ";
                }
            }
        }
        cout << endl;
    }
    return 0;
}
