/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
    public:
    void RotateImage(vector<vector<int>>& img, int N) {
        for (int L=0; L<N/2; L++) {
            for (int n=L; n<N-L-1; n++) {
                int top = img[L][n];
                img[L][n] = img[N-n-1][L]; // left
                img[N-n-1][L] = img[N-L-1][N-n-1]; // bottom
                img[N-L-1][N-n-1] = img[n][N-L-1]; // right
                img[n][N-L-1] = top;
            }
        }
    }

    void Display(vector<vector<int>>& img, int N) {
        for (int r=0; r<N; r++) {
            for (int c=0; c<N; c++) {
                cout << img[r][c] << " ";
            }
            cout << endl;
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int N;
    cin >> N;

    vector<vector<int>> img(N, vector<int>(N));
    for (int r=0; r<N; r++) {
        for (int c=0; c<N; c++) {
            cin >> img[r][c];
        }
    }

    sol.RotateImage(img, N);
    sol.Display(img, N);

    return 0;
}
