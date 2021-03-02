#include "LCHeader.h"
//add greedy nature
/*
Runtime: 4 ms, faster than 80.37% of C++ online submissions for Shortest Way to Form String.
Memory Usage: 41.7 MB, less than 5.08% of C++ online submissions for Shortest Way to Form String.
*/
class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> set(source.cbegin(), source.cend());
        for (auto& x : target) {
            if (set.count(x) == 0) {
                return -1;
            }
        }
        vector<vector<int>> memo(source.size() + 1, vector<int>(target.size() + 1, -1));
        int t = 0;
        int count = 0;
        while (t != target.size()) {
            t = dp(source, target, 0, t, memo);
            count++;
        }
        return count;
    }

    int dp(string& source, string& target, int s, int t, vector<vector<int>>& memo) {
        if (memo[s][t] != -1) {
            return memo[s][t];
        }
        if (t == target.size() || s == source.size()) {
            return memo[s][t] = t;
        }
        if (source[s] == target[t]) {
            return memo[s][t] = dp(source, target, s + 1, t + 1, memo);
        }
        return  memo[s][t] = dp(source, target, s + 1, t, memo);
    }
};


//3:55 4:28 a bit slow, going a wrong way
/*
Runtime: 84 ms, faster than 5.77% of C++ online submissions for Shortest Way to Form String.
Memory Usage: 41.6 MB, less than 5.08% of C++ online submissions for Shortest Way to Form String.
*/
class Solution {
public:
    int shortestWay(string source, string target) {
        unordered_set<char> set(source.cbegin(), source.cend());
        for (auto& x : target) {
            if (set.count(x) == 0) {
                return -1;
            }
        }
        vector<vector<int>> memo(source.size() + 1, vector<int>(target.size() + 1, -1));
        int t = 0;
        int count = 0;
        while (t != target.size()) {
            t = dp(source, target, 0, t, memo);
            count++;
        }
        return count;
    }

    int dp(string& source, string& target, int s, int t, vector<vector<int>>& memo) {
        if (memo[s][t] != -1) {
            return memo[s][t];
        }
        if (t == target.size() || s == source.size()) {
            return memo[s][t] = t;
        }
        if (source[s] == target[t]) {
            return memo[s][t] = memo[s][t] = std::max(dp(source, target, s + 1, t + 1, memo), dp(source, target, s + 1, t, memo));
        }
        return  memo[s][t] = dp(source, target, s + 1, t, memo);
    }
};