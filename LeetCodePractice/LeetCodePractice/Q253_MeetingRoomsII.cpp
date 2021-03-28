#include "LCHeader.h"
#include<queue>
//7:49 8:01

class Solution {//7:49 8:01
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        priority_queue<int, vector<int>, std::greater<int>> pq;
        int min = 0;
        auto cmp = [](const vector<int>& left, const vector<int>& right) {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }
            else {
                return left[0] < right[0];
            }
        };
        sort(intervals.begin(), intervals.end(), cmp);
        for (int i = 0; i < intervals.size(); i++) {
            auto& x = intervals[i];
            while (pq.size() > 0 && pq.top() <= x[0]) {
                pq.pop();
            }
            pq.push(x[1]);
            min = std::max(min, (int)pq.size());
        }
        return min;
    }
};