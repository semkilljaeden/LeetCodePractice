#include "LCHeader.h"
//10:29 10:56 AC
/*
Runtime: 20 ms, faster than 70.81% of C++ online submissions for Push Dominoes.
Memory Usage: 13.7 MB, less than 17.87% of C++ online submissions for Push Dominoes.
*/

class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> L(n, 0);
        vector<int> R(n, 0);
        vector<char> LC(n, 0);
        vector<char> RC(n, 0);
        int prev = -1;
        char x = '.';
        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') {
                prev = i;
            }
            R[i] = i - prev;
            if (s[i] != '.') {
                x = s[i];
            }
            LC[i] = x;
        }
        prev = -1;
        x = '.';
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'L') {
                prev = i;
            }
            L[i] = prev - i;
            if (s[i] != '.') {
                x = s[i];
            }
            RC[i] = x;
        }
        for (int i = n - 1; i >= 0; i--) {
            if (s[i] == 'L' || s[i] == 'R') {
                continue;
            }
            if (RC[i] == 'L' && (LC[i] == 'L' || LC[i] == '.')) {
                s[i] = 'L';
            }
            else if (LC[i] == 'R' && (RC[i] == 'R' || RC[i] == '.')) {
                s[i] = 'R';
            }
            else if (LC[i] == 'R' && RC[i] == 'L') {
                if (L[i] > R[i]) {
                    s[i] = 'R';
                }
                else if (L[i] == R[i]) {
                    continue;
                }
                else {
                    s[i] = 'L';
                }
            }
            else if (LC[i] == 'L' && RC[i] == 'R') {
                continue;
            }
        }
        return s;
    }
};