// Copyright (C) yckuo - All Rights Reserved

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    void ZeroMatrix(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int R = matrix.size(), C = matrix[0].size();
        
        bool firstRowHasZero = false, firstColHasZero = false;
        for (int c=0; c<C; c++) if (matrix[0][c] == 0) firstRowHasZero = true;
        for (int r=0; r<R; r++) if (matrix[r][0] == 0) firstColHasZero = true;
        for (int r=1; r<R; r++) {
            for (int c=1; c<C; c++) {
                if (matrix[r][c] == 0) {
                    matrix[0][c] = 0;
                    matrix[r][0] = 0;
                }
            }
        }

        for (int r=1; r<R; r++) {
            for (int c=1; c<C; c++) {
                if (matrix[0][c] == 0 || matrix[r][0] == 0) matrix[r][c] = 0;
            }
        }

        if (firstRowHasZero) for (int c=0; c<C; c++) matrix[0][c] = 0;
        if (firstColHasZero) for (int r=0; r<R; r++) matrix[r][0] = 0;
    }

    void Print(vector<vector<int>>& matrix) {
        if (matrix.empty() || matrix[0].empty()) return;
        int R = matrix.size(), C = matrix[0].size();
        for (int r=0; r<R; r++) {
            for (int c=0; c<C; c++) {
                cout << matrix[r][c] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    int R, C;
    cin >> R >> C;
    vector<vector<int>> matrix(R, vector<int>(C));
    for (int r=0; r<R; r++) {
        for (int c=0; c<C; c++) {
            cin >> matrix[r][c];
        }
    }

    Solution sol;
    sol.ZeroMatrix(matrix);
    sol.Print(matrix);

    return 0;
}
