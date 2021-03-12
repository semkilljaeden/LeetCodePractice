#include "LCHeader.h"
//9:33 10:32 11:31 TLE DP works! fuck this shit!
/*
Runtime: 8 ms, faster than 75.95% of C++ online submissions for Remove Invalid Parentheses.
Memory Usage: 21.1 MB, less than 31.59% of C++ online submissions for Remove Invalid Parentheses.
*/
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        vector<vector<int>> memo(n + 1, vector<int>(n + 1, -1));
        vector<vector<vector<vector<int>>>> memo2(n + 1, vector<vector<vector<int>>>(n + 1, vector<vector<int>>()));
        auto tmp = dp(s, 0, 0, memo, memo2, "");
        unordered_set<string> k;
        for (auto& x : memo2[0][0]) {
            int idx = x.size() - 1;
            string tmp;
            for (int i = 0; i < s.size(); i++) {
                if (idx >= 0 && i == x[idx]) {
                    idx--;
                    continue;
                }
                tmp += s[i];
            }
            k.insert(tmp);
        }
        vector<string> result(k.cbegin(), k.cend());
        return result;
    }
    int dp(string& s, int idx, int count, vector<vector<int>>& memo, vector<vector<vector<vector<int>>>>& memo2, string v) {
        if (memo[idx][count] != -1) {
            return memo[idx][count];
        }
        if (idx == s.size()) {
            if (count == 0) {
                memo2[idx][count].push_back(vector<int>());
                return memo[idx][count] = 0;
            }
            return memo[idx][count] = 10000000;
        }
        int result = 0;
        if (s[idx] == '(') {
            auto left = dp(s, idx + 1, count + 1, memo, memo2, v + s[idx]);
            auto right = 1 + dp(s, idx + 1, count, memo, memo2, v);
            if (left < right) {
                memo2[idx][count] = memo2[idx + 1][count + 1];
                result = left;
            }
            else if (right < left) {
                memo2[idx][count] = memo2[idx + 1][count];
                for (auto& x : memo2[idx][count]) {
                    x.push_back(idx);
                }
                result = right;
            }
            else {
                memo2[idx][count] = memo2[idx + 1][count + 1];
                for (auto x : memo2[idx + 1][count]) {
                    x.push_back(idx);
                    memo2[idx][count].push_back(move(x));
                }
                result = left;
            }
        }
        else if (s[idx] == ')') {
            int left = 100000000;
            if (count > 0) {
                left = dp(s, idx + 1, count - 1, memo, memo2, v + s[idx]);
            }
            auto right = 1 + dp(s, idx + 1, count, memo, memo2, v);
            if (left < right) {
                memo2[idx][count] = memo2[idx + 1][count - 1];
                result = left;
            }
            else if (right < left) {
                memo2[idx][count] = memo2[idx + 1][count];
                for (auto& x : memo2[idx][count]) {
                    x.push_back(idx);
                }
                result = right;
            }
            else {
                memo2[idx][count] = memo2[idx + 1][count - 1];
                for (auto x : memo2[idx + 1][count]) {
                    x.push_back(idx);
                    memo2[idx][count].push_back(move(x));
                }
                result = left;
            }
        }
        else {
            result = dp(s, idx + 1, count, memo, memo2, v + s[idx]);
            memo2[idx][count] = memo2[idx + 1][count];
        }
        return memo[idx][count] = result;
    }
};






class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        auto tmp = dp(s, 0, 0);
        unordered_set<string> set;
        for (auto& x : tmp.second) {
            string t;
            unordered_set<int> check(x.cbegin(), x.cend());
            for (int i = 0; i < s.size(); i++) {
                if (check.count(i) > 0) {
                    continue;
                }
                t += s[i];
            }

            set.insert(t);
        }
        vector<string> result(set.cbegin(), set.cend());
        return result;
    }
    pair<int, vector<vector<int>>> dp(string& s, int idx, int count) {
        if (idx == s.size()) {
            if (count == 0) {
                return make_pair(0, vector<vector<int>> {vector<int>()});
            }
            return make_pair(10000000, vector<vector<int>> {vector<int>()});
        }
        if (s[idx] == '(') {
            auto left = dp(s, idx + 1, count + 1);
            auto right = dp(s, idx + 1, count);
            if (left.first < right.first) {
                return left;
            }
            else if (right.first + 1 < left.first) {
                for (auto& x : right.second) {
                    x.push_back(idx);
                }
                right.first++;
                return right;
            }
            else {
                for (auto& x : right.second) {
                    x.push_back(idx);
                    left.second.push_back(move(x));
                }
                return left;
            }
        }(
        else if (s[idx] == ')') {
            auto left = make_pair(10000000, vector<vector<int>> {vector<int>()});
            if (count > 0) {
                left = dp(s, idx + 1, count - 1);
            }
            auto right = dp(s, idx + 1, count);

            if (left.first < right.first) {
                return left;
            }
            else if (right.first + 1 < left.first) {
                for (auto& x : right.second) {
                    x.push_back(idx);
                }
                right.first++;
                return right;
            }
            else {
                for (auto& x : right.second) {
                    x.push_back(idx);
                    left.second.push_back(move(x));
                }
                return left;
            }
        }
        return dp(s, idx + 1, count);
    }
};