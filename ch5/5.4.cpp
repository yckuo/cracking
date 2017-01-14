/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class Solution {
public:
    int next(int x) {
        int c0 = 0, c1 = 0;
        int tmp = x;
        bool valid = false;
        for (int i=0; i<32; i++) {
            if (!(tmp & 1)) {
                if (c1) {
                    valid = true;
                    break;
                }
                c0++;
            } else {
                c1++;
            }

            tmp = tmp >> 1;
        }

        if (!valid) return x;

        return ((tmp + 1) << (c1 + c0)) + ((1 << (c1-1)) - 1);
    }

    int prev(int x) {
        bool valid =false;
        int c0 = 0, c1 = 0, tmp = x;
        for (int i=0; i<32; i++, tmp = tmp >> 1) {
            if (tmp % 2 == 1) {
                if (c0) {
                    valid = true;
                    break;
                }
                c1++;
            } else {
                c0++;
            }
        }

        if (!valid) return x;
        int allOnes = (1 << (c1 + 1)) - 1;
        return ((tmp - 1) << (c1 + c0)) | (allOnes << (c0-1));
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int x;
    while (cin >> x) {
        int y = sol.next(x);
        int z = sol.prev(x);
        cout << x << " " << bitset<32>(x) << " next = " << bitset<32>(y) << "; prev = " << bitset<32>(z) << endl;
    }

    return 0;
}
