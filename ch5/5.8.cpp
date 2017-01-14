/* Copyright (C) yckuo - All Rights Reserved */

#include <iostream>
#include <fstream>
#include <vector>
#include <bitset>
using namespace std;

class Solution {
public:
    void drawLine(vector<char>& screen, int width, int x1, int x2, int y) {
        int start_offset = x1 % 8;
        int start_fullbyte = x1 / 8;
        if (start_offset != 0) start_fullbyte++;

        int end_offset = x2 % 8;
        int end_fullbyte = x2 / 8;
        if (end_offset != 7) end_fullbyte--;

        for (int b=start_fullbyte; b<=end_fullbyte; b++) {
            screen[width / 8 * y + b] = 0xFF;
        }

        unsigned char allOnes = 0xFF;
        if (x1 / 8 == x2 / 8) {
            // x1 and x2 are within the same byte
            unsigned char val = (allOnes >> start_offset) & ~(allOnes >> (end_offset + 1));
            screen[width / 8 * y + x1 / 8] = val;
        } else {
            screen[width / 8 * y + x1 / 8] = allOnes >> start_offset;
            screen[width / 8 * y + x2 / 8] = ~(allOnes >> (end_offset + 1));
        }
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;

    int H, W, x1, x2, y;
    while (cin >> H >> W >> x1 >> x2 >> y) {
        vector<char> screen(H * W / 8, 0x00);
        sol.drawLine(screen, W, x1, x2, y);

        for (int h=0; h<H; h++) {
            for (int w=0; w<W/8; w++) {
                char ch = screen[(h * W / 8) + w];
                cout << bitset<8>(ch);
            }
            cout << endl;
        }
        cout << endl << endl;
    }

    return 0;
}
