/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <bitset>
using namespace std;

class Solution {
public:
    int insert(int n, int m, int i, int j) {
        int left = (1 << (j + 1)) - 1; // 01111111 for j = 6 (7 one's)
        int right = (1 << i) - 1; // 00000011 for i = 2
        int diff = left - right; // 01111100 for i = 2, j = 6
        int mask = ~diff; // 10000011
        n = n & mask;
        int m_shift = m << i;
        return n | m_shift;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    char *cend;
    string nstr, mstr;
    int n, m, i, j;
    while(cin >> nstr >> mstr >> i >> j) {
        n = (int)strtol(nstr.c_str(), &cend, 2);
        m = (int)strtol(mstr.c_str(), &cend, 2);
        int ret = sol.insert(n, m, i, j);
        cout << bitset<32>(ret) << endl;
    }
    return 0;
}
