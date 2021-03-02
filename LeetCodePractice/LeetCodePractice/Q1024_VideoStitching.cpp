#include "LCHeader.h"
//2:58 DP
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Video Stitching.
Memory Usage: 8.1 MB, less than 32.60% of C++ online submissions for Video Stitching.
*/
class Solution {
public:
    int T;
    const int MAX = 1000000;
    int videoStitching(vector<vector<int>>& newClip, int T) {
        if (T == 0) {
            return 0;
        }
        this->T = T;
        sort(newClip.begin(), newClip.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
        vector<vector<int>> memo(newClip.size(), vector<int>(T, -1));
        int r = dp(newClip, 0, 0, memo);
        return r >= MAX ? -1 : r;
    }
    int dp(vector<vector<int>>& clips, int idx, int dis, vector<vector<int>>& memo) {
        if (dis >= T) {
            return 0;
        }
        if (idx >= clips.size()) {
            return MAX;
        }
        if (memo[idx][dis] != -1) {
            return memo[idx][dis];
        }
        auto& x = clips[idx];
        if (x[0] > dis) {
            return memo[idx][dis] = MAX;
        }
        return memo[idx][dis] = std::min(1 + dp(clips, idx + 1, x[1], memo), dp(clips, idx + 1, dis, memo));
    }
};




//2:46 



/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Video Stitching.
Memory Usage: 7.7 MB, less than 61.40% of C++ online submissions for Video Stitching.
*/
class Solution {
public:
    int T;
    const int MAX = 1000000;
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) {
            return 0;
        }
        this->T = T;
        unordered_map<int, int> tmp;

        for (int i = 0; i < clips.size(); i++) {
            if (clips[i][1] > tmp[clips[i][0]]) {
                tmp[clips[i][0]] = clips[i][1];
            }
        }
        vector<vector<int>> newClip;
        for (auto& x : tmp) {
            newClip.push_back(vector<int>{x.first, x.second});
        }
        sort(newClip.begin(), newClip.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
        if (newClip[0][0] != 0) {
            return -1;
        }
        int count = 1;
        int limit = newClip[0][1];
        for (int i = 1; i < newClip.size();) {
            if (limit >= T) {
                return count;
            }
            int j = i;
            int tmp = limit;
            for (; j < newClip.size(); j++) {
                if (newClip[j][0] > limit) {
                    break;
                }
                if (newClip[j][1] > tmp) {
                    tmp = newClip[j][1];
                }
            }
            if (j == i) {
                return -1;
            }
            if (tmp > limit) {
                count++;
                limit = tmp;
            }
            i = j;
        }
        return limit >= T ? count : -1;
    }
};

//1:47 2:19 TLE

class Solution {
public:
    int T;
    const int MAX = 1000000;
    int videoStitching(vector<vector<int>>& clips, int T) {
        if (T == 0) {
            return 0;
        }
        this->T = T;
        unordered_map<int, int> tmp;

        for (int i = 0; i < clips.size(); i++) {
            if (clips[i][1] > tmp[clips[i][0]]) {
                tmp[clips[i][0]] = clips[i][1];
            }
        }
        vector<vector<int>> newClip;
        for (auto& x : tmp) {
            newClip.push_back(vector<int>{x.first, x.second});
        }
        sort(newClip.begin(), newClip.end(), [](const vector<int>& a, const vector<int>& b) {return a[0] < b[0]; });
        if (newClip[0][0] != 0) {
            return -1;
        }
        vector<int> memo(newClip.size(), -1);
        int min = dp(newClip, 0, memo);
        return min > 100000 ? -1 : min;
    }

    int dp(vector<vector<int>>& clips, int idx, vector<int> memo) {
        if (memo[idx] != -1) {
            return memo[idx];
        }
        auto& cur = clips[idx];
        if (cur[1] >= T) {
            return memo[idx] = 1;
        }
        int min = MAX;
        for (int i = idx + 1; i < clips.size(); i++) {
            auto& next = clips[i];
            if (next[0] <= cur[1] && next[0] != cur[0]) {
                min = std::min(min, 1 + dp(clips, i, memo));
            }
        }
        return memo[idx] = min;
    }
};