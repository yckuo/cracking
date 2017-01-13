/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class Solution {
public:
    int longestSequence(unsigned int x) { // input number needs to be cast to unsigned int first to perform logical shift (default >> behavior is arithmetic shift, where signs are preserved)
        
        int len = 0, prev = 0, ret = 0;
        while (x > 0) {
            int b = x & 1;
            x = x >> 1;
            if (b == 0) {
                ret = max(ret, 1 + len + prev);
                prev = len;
                len = 0;
            } else {
                len++;
            }
        }
        ret = max(ret, 1 + len + prev);

        return ret;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int x;

    while (cin >> x) {
        cout << x << " " << bitset<32>(x) << " " << sol.longestSequence(x) << endl;
    }

    return 0;
}
