#include <iostream>
#include <fstream>
using namespace std;

class Solution {
public:
    string StringCompression(string str) {
        string ret = "";
        for (int i=0, count=1; i<str.size(); i++, count++) {
            if (i + 1 == str.size() || str[i] != str[i+1]) {
                ret = ret + string(1, str[i]) + to_string(count);
                count = 0;
            }
        }
        if (ret.size() >= str.size()) return str;
        return ret;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string str;
    while (cin >> str) {
        cout << sol.StringCompression(str) << ";" << str << endl;
    }
    return 0;
}
