/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Solution {
public:
    string URLify(string str, int len) {
        int len2 = len;
        for (int i=0; i<len; i++) {
            if (str[i] == ' ') len2 += 2;
        }

        for (int i=len-1; i>=0; i--) {
            if (str[i] == ' ') {
                str[--len2] = '0';
                str[--len2] = '2';
                str[--len2] = '%';
            } else {
                str[--len2] = str[i];
            }
        }
        return str;
    }
};
    

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string str, line;
    int len;
    while (getline(cin, line)) {
        int idx = line.size()-1;
        while (idx > 0 && line[idx] != ' ') idx--;
        str = line.substr(0, idx);
        len = atoi(line.substr(idx+1).c_str());
        cout << str << ";" << sol.URLify(str, len) << endl;
    }

    return 0;
}
