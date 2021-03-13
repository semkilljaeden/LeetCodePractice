#include "LCHeader.h"
//2:50 3:02
/*
Runtime: 4 ms, faster than 98.35% of C++ online submissions for Permutation in String.
Memory Usage: 7.3 MB, less than 76.30% of C++ online submissions for Permutation in String.
*/
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size()) {
            return false;
        }
        vector<int> p1(26, 0);
        for (auto& x : s1) {
            p1[x - 'a']++;
        }
        int i = 0;
        int j = 0;
        vector<int> p2(26, 0);
        for (; i < s1.size(); i++) {
            p2[s2[i] - 'a']++;
        }
        if (equals(p1, p2)) {
            return true;
        }
        for (; i < s2.size(); i++) {
            p2[s2[j] - 'a']--;
            p2[s2[i] - 'a']++;
            if (equals(p1, p2)) {
                return true;
            }
            j++;
        }
        return false;
    }

    inline bool equals(const vector<int>& left, const vector<int>& right) {
        for (int i = 0; i < 26; i++) {
            if (left[i] != right[i]) {
                return false;
            }
        }
        return true;
    }
};