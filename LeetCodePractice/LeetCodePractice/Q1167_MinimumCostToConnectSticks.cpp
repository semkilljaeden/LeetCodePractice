#include "LCHeader.h"
#include<queue>
/*
Runtime: 68 ms, faster than 92.40% of C++ online submissions for Minimum Cost to Connect Sticks.
Memory Usage: 22.7 MB, less than 98.15% of C++ online submissions for Minimum Cost to Connect Sticks.
*/
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, std::greater<int>> pq(sticks.cbegin(), sticks.cend());
        int sum = 0;
        while (pq.size() > 1) {
            int f = pq.top();
            pq.pop();
            int s = pq.top();
            pq.pop();
            int n = f + s;
            sum += n;
            pq.push(n);
        }
        return sum;
    }
};