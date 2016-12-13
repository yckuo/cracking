#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool IsPalindromePermutation(string line) {
        vector<bool> odd(26, false);
        for (char ch : line) {
            if (ch <= 'z' && ch >= 'a') odd[ch-'a'] = !odd[ch-'a'];
            else if (ch <= 'Z' && ch >= 'A') odd[ch-'A'] = !odd[ch-'A'];
        }
        bool oddSeen = false;
        for (bool o : odd) {
            if (o) {
                if (oddSeen) return false;
                oddSeen = true;
            }
        }
        return true;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string line;
    while(getline(cin, line)) {
        cout << sol.IsPalindromePermutation(line) << ";" << line << endl;
    }
    return 0;
}
