/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <sstream>
#include <list>
using namespace std;

class ListNode {
public:
    ListNode(string name, bool isDog, int timestamp) : name(name), isDog(isDog), timestamp(timestamp) {
    }
    string name;
    bool isDog;
    int timestamp;
};

class Solution {
public:
    Solution() : timestamp(0) {
    }

    void Enqueue(string name, bool isDog) {
        if (isDog) dogs.push_back(ListNode(name, true, timestamp++));
        else cats.push_back(ListNode(name, false, timestamp++));
    }

    string DequeueAny() {
        if (dogs.empty() && cats.empty()) return "#";
        string ret = "#";
        if (dogs.empty()) {
            ret = cats.front().name;
            cats.pop_front();
        } else if (cats.empty()) {
            ret = dogs.front().name;
            dogs.pop_front();
        } else {
            ListNode dog = dogs.front(), cat = cats.front();
            if (dog.timestamp < cat.timestamp) {
                ret = dog.name;
                dogs.pop_front();
            } else {
                ret = cat.name;
                cats.pop_front();
            }
        }
        return ret;
    }

    string DequeueDog() {
        if (dogs.empty()) return "#";
        string ret = dogs.front().name;
        dogs.pop_front();
        return ret;
    }

    string DequeueCat() {
        if (cats.empty()) return "#";
        string ret = cats.front().name;
        cats.pop_front();
        return ret;
    }
private:
    list<ListNode> dogs, cats;
    int timestamp;
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    string line;
    while (getline(cin, line)) {
        istringstream iss(line);
        Solution sol;
        string token, name;
        int dogOrCat;
        while (iss >> token) {
            if (token == "e") {
                iss >> name >> dogOrCat;
                sol.Enqueue(name, dogOrCat == 1);
                cout << "enqueued";
            } else if (token == "a") {
                cout << sol.DequeueAny();
            } else if (token == "d") {
                cout << sol.DequeueDog();
            } else if (token == "c") {
                cout << sol.DequeueCat();
            }
            cout << " ";
        }
        cout << endl;
    }
    
    return 0;
}

