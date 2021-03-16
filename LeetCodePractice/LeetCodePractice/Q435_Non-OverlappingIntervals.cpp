#include "LCHeader.h"

//10:49 LIS, damn stupid

class Solution {
public:
    int offset;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals[0].size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right) {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }
            return left[0] < right[0];
        });
        vector<int> memo(intervals.size(), -1);
        return intervals.size() - dp(intervals, 0, memo);
    }

    int dp(vector<vector<int>>& intervals, int idx, vector<int>& memo) {
        if (memo[idx] != -1) {
            return memo[idx];
        }
        auto& cur = intervals[idx];
        int max = 1;
        for (int i = idx + 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= cur[1]) {
                max = std::max(max, 1 + dp(intervals, i, memo));
            }
        }
        return memo[idx] = max;
    }
};


//10:11 10:42 failed, DP model chooses wrongly
class Solution {
public:
    int offset;
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0 || intervals[0].size() == 0) {
            return 0;
        }
        sort(intervals.begin(), intervals.end(), [](const vector<int>& left, const vector<int>& right) {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }
            return left[0] < right[0];
        });
        offset = intervals[0][0] < 0 ? abs(intervals[0][0]) : 0;
        int end = INT_MIN;
        for (auto& x : intervals) {
            if (x[1] > end) {
                end = x[1];
            }
        }
        vector<vector<int>> memo(intervals.size(), vector<int>(offset + end + 1, -1));
        return dp(intervals, 0, 0, memo);
    }

    int dp(vector<vector<int>>& intervals, int idx, int end, vector<vector<int>>& memo) {
        if (idx == intervals.size()) {
            return 0;
        }
        if (memo[idx][end] != -1) {
            return memo[idx][end];
        }
        auto& cur = intervals[idx];
        if (cur[0] + offset < end) {
            return memo[idx][end] = 1 + dp(intervals, idx + 1, end, memo);
        }
        return memo[idx][end] = std::min(dp(intervals, idx + 1, cur[1] + offset, memo), 1 + dp(intervals, idx + 1, end, memo));
    }
};