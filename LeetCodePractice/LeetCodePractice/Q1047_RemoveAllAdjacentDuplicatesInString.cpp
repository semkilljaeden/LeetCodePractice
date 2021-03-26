#include "LCHeader.h"
//2:48 ..... wrong direction

class Solution {
public:
    string removeDuplicates(string S) {
        string r = "1";
        for (int i = 0; i < S.size(); i++) {
            if (S[i] != r.back()) {
                r += S[i];
            }
            else {
                r.pop_back();
            }
        }
        return r.substr(1, r.size() - 1);
    }
};