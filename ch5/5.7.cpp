/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class Solution {
public:
    int pairwiseSwap(int x) {
        return ((x & 0xAAAAAAAA) >> 1) | ((x & 0x55555555) << 1);
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int x;
    while (cin >> x) {
        int y = sol.pairwiseSwap(x);
        cout << bitset<32>(x) << " -> " << bitset<32>(y) << endl;
    }

    return 0;
}
