#include "LCHeader.h"
//9:47 9:56 too easy
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Bulls and Cows.
Memory Usage: 6.7 MB, less than 64.86% of C++ online submissions for Bulls and Cows.
*/
class Solution {
public:
    string getHint(string secret, string guess) {
        int a = 0;
        vector<int> s(26, 0);
        vector<int> g(26, 0);
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                a++;
            }
            s[secret[i] - '0']++;
            g[guess[i] - '0']++;
        }
        int b = 0;
        for (int i = 0; i < 26; i++) {
            b += std::min(s[i], g[i]);
        }
        b -= a;
        return to_string(a) + "A" + to_string(b) + "B";
    }
};