#include "LCHeader.h"
//1:53 to 1:59

class Solution {//1:53
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> result;
        rec(word, 0, "", 0, result);
        return result;
    }

    void rec(string& word, int idx, string tmp, int prev, vector<string>& result) {
        if (idx == word.size()) {
            result.push_back(tmp + (prev > 0 ? to_string(prev) : ""));
            return;
        }
        if (prev > 0) {
            rec(word, idx + 1, tmp + to_string(prev) + word[idx], 0, result);
        }
        else {
            rec(word, idx + 1, tmp + word[idx], 0, result);
        }
        rec(word, idx + 1, tmp, prev + 1, result);
        return;
    }
};