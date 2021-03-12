#include "LCHeader.h"
//10:06
/*
*/

//wrong
class Solution {
public:
    bool canConvert(string str1, string str2) {
        vector<int> code1(26, 0);
        vector<int> code2(26, 0);
        for (int i = 0; i < str1.size(); i++) {
            code1[str1[i] - 'a']++;
            code2[str2[i] - 'a']++;
        }
        sort(code1.begin(), code1.end(), std::greater<int>());
        sort(code2.begin(), code2.end(), std::greater<int>());
        return dp(code1, code2, 0);
    }

    bool dp(vector<int>& code1, vector<int>& code2, int idx) {
        if (idx >= 26) {
            return true;
        }
        if (code1[idx] > code2[idx]) {
            return false;
        }
        if (code1[idx] == code2[idx]) {
            return dp(code1, code2, idx + 1);
        }
        bool result = false;
        for (int i = 0; i < 26; i++) {
            if (i != idx && code1[i] != 0) {
                int tmp = code1[i];
                if (code1[idx] + tmp > code2[idx]) {
                    continue;
                }
                code1[idx] += tmp;
                code1[i] = 0;
                int newIdx = code1[idx] + tmp < code2[idx] ? idx : idx + 1;
                result |= dp(code1, code2, idx);

                code1[idx] -= tmp;
                code1[i] = tmp;
            }
        }
        return result;
    }
};