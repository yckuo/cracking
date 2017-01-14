/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class Solution {
public:
    int NumBitsConversion(int a, int b) {
        int ret = 0;
        for (int x = a ^ b; x; x = x & (x-1)) ret++;
        return ret;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;

    int x, y;
    while (cin >> x >> y) {
        cout << bitset<32>(x) << " - " << bitset<32>(y) << " - " << sol.NumBitsConversion(x, y) << endl;
    }

    return 0;
}
