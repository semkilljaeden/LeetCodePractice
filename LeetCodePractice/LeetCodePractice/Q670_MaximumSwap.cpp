#include "LCHeader.h"
//4:36

class Solution {//4:27
public:
    int maximumSwap(int n) {
        int max = 0;
        int max_pos = 0;
        int left = 0;
        int right = 0;
        string s = to_string(n);
        for (int i = s.size() - 1; i >= 0; i--) {
            int cur = s[i] - '0';
            if (cur < max) {
                left = i;
                right = max_pos;
            }
            if (cur > max) {
                max = cur;
                max_pos = i;
            }
        }
        swap(s[left], s[right]);
        return stoi(s);
    }
};