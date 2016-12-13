/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
using namespace std;

class Solution {
public:
    // One or zero edit away
    bool OneAway(string str1, string str2) {
        int idx = 0, N1 = str1.size(), N2 = str2.size();
        while (idx < N1 && idx < N2 && str1[idx] == str2[idx]) idx++;
        if (idx == N1 && idx == N2) return true;
        if (idx < N1 && idx < N2) {
            if (N1 == N2) return str1.substr(idx+1) == str2.substr(idx+1);
            if (N1 > N2) return str1.substr(idx+1) == str2.substr(idx);
            return str1.substr(idx) == str2.substr(idx);
        } else if (idx == N2) return idx + 1 == N1;
        else return idx + 1 == N2;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << sol.OneAway(str1, str2) << ";" << str1 << ";" << str2 << endl;
    }
    return 0;
}
