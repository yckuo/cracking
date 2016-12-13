/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    bool StringRotation(string str1, string str2) {
        if (str1.size() != str2.size()) return false;
        return IsSubStr(str1, str2 + str2);
    }
private:
    bool IsSubStr(string str1, string str2) {
        // checks whether str1 is a substring of str2 using KMP;
        vector<int> prefix(str1.size(), 0);
        for (int i=1, j=0; i<str1.size(); i++) {
            while (j > 0 && str1[i] != str1[j]) j = prefix[j-1];
            if (str1[i] == str1[j]) {
                prefix[i] = j + 1;
                j++;
            }
        }

        for (int i=0, j=0; i<str2.size(); i++) {
            while (j > 0 && str2[i] != str1[j]) j = prefix[j-1];
            if (str2[i] == str1[j]) {
                if (++j == str1.size()) return true;
            }
        }

        return false;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string str1, str2;
    while (cin >> str1 >> str2) {
        cout << sol.StringRotation(str1, str2) << ";" << str1 << ";" << str2 << endl;
    }

    return 0;
}
