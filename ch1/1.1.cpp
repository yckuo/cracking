/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
   bool IsUnique(string str) {
      int used = 0;
      for (char ch : str) {
         int b = 1 << (ch - 'a');
         if (used & b) return false;
         used |= b;
      }
      return true;
   }

   bool IsUnique2(string str) {
      sort(str.begin(), str.end());
      for (int i=1; i<str.size(); i++) {
         if (str[i] == str[i-1]) return false;
      }
      return true;
   }
};

int main(int argc, char** argv) {
   freopen(argv[1], "r", stdin);
   string str;
   
   Solution sol;
   while (cin >> str) {
      cout << sol.IsUnique(str) << ";" << sol.IsUnique2(str) << ";" << str << endl;
   }

   return 0;
}
