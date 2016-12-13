/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
   bool CheckPermutation(string str1, string str2) {
      if (str1.size() != str2.size()) return false;
      unordered_map<char, int> count;
      for (int i=0; i<str1.size(); i++) {
         count[str1[i]]++;
         count[str2[i]]--;
      }
      for (auto it : count) {
         if (it.second != 0) return false;
      }
      return true;
   }

   bool CheckPermutation2(string str1, string str2) {
      if (str1.size() != str2.size()) return false;
      sort(str1.begin(), str1.end());
      sort(str2.begin(), str2.end());
      for (int i=0; i<str1.size(); i++) {
         if (str1[i] != str2[i]) return false;
      }
      return true;
   }
};

int main(int argc, char** argv) {
   freopen(argv[1], "r", stdin);
   Solution sol;
   string str1, str2;
   while (cin >> str1 >> str2) {
      cout << sol.CheckPermutation(str1, str2) << ";" << sol.CheckPermutation2(str1, str2) << ";" << str1 << ";" << str2 << endl;
   }
   return 0;
}
