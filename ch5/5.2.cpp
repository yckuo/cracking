/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>

using namespace std;

class Solution {
public:
    string toBinary(double x) {
        if (x == 0) return "0";
        if (x == 1) return "1";
        if (x < 0 || x > 1) return "ERROR";

        int n = 2;
        string ret = "0.";
        while (x != 0 && n <= 32) {
            x *= 2;
            if (x >= 1) {
                ret = ret + "1";
                x -= 1;
            } else {
                ret = ret + "0";
            }
            n++;
        }

        if (n > 32) return "ERROR";
        return ret;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    double x;
    while (cin >> x) {
        cout << sol.toBinary(x) << endl;
    }
    return 0;
}
