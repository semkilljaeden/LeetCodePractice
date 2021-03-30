#include "LCHeader.h"
/*
Runtime: 4 ms, faster than 97.95% of C++ online submissions for Swap Adjacent in LR String.
Memory Usage: 7.4 MB, less than 77.65% of C++ online submissions for Swap Adjacent in LR String.
*/
class Solution {//10:51 11£»14
public:
    bool canTransform(string start, string end) {
        int r = 0;
        int l = 0;
        for (int i = 0; i < start.size(); i++) {
            if (start[i] == 'X' && end[i] == 'X') {
                continue;
            }
            if (start[i] == 'R') {
                r++;
                if (l > 0) {
                    return false;
                }
            }
            if (end[i] == 'R') {
                r--;
                if (l > 0) {
                    return false;
                }
            }
            if (end[i] == 'L') {
                l++;
                if (r > 0) {
                    return false;
                }
            }
            if (start[i] == 'L') {
                l--;
                if (r > 0) {
                    return false;
                }
            }
            if (r < 0 || l < 0) {
                return false;
            }
        }
        if (r < 0 || l < 0 || r > 0 || l > 0) {
            return false;
        }
        return true;
    }
};