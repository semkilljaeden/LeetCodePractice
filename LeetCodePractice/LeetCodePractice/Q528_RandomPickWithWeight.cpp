#include "LCHeader.h"
//3:05 3:31 funny question

class Solution {
public:
    map<int, int> m;
    int sum;
    Solution(vector<int>& w) {
        sum = 0;
        for (int i = 0; i < w.size(); i++) {
            auto& x = w[i];
            m[sum] = i;
            sum += x;
            m[sum - 1] = i;
        }
    }

    int pickIndex() {
        int target = rand() % sum;
        auto x = m.lower_bound(target);
        return x->second;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */