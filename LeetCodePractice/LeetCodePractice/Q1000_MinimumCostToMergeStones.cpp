#include "LCHeader.h"
//10:53 read answer

class Solution {
public:
    int K;
    vector<int> sum;
    int mergeStones(vector<int>& stones, int K) {
        if (stones.size() == 0 || stones.size() == 1) {
            return 0;
        }
        this->K = K;
        int prev = 0;
        sum.reserve(stones.size());
        for (int i = 0; i < stones.size(); i++) {
            sum[i] = stones[i] + prev;
            prev = sum[i];
        }
        vector<vector<vector<int>>> memo(stones.size(), vector<vector<int>>(stones.size(), vector<int>(K + 1, -1)));
        int r = dp(stones, 0, stones.size() - 1, 1, memo);
        if (r > 100000) {
            return -1;
        }
        return r;
    }
    int dp(vector<int>& s, int left, int right, int k, vector<vector<vector<int>>>& memo) {
        if (memo[left][right][k] != -1) {
            return memo[left][right][k];
        }
        if (k == 0) {
            return memo[left][right][k] = 1000000;
        }
        if (k == 1) {
            if (left == right) {
                return memo[left][right][k] = 0;
            }
            else if (right - left + 1 < K) {
                return memo[left][right][k] = 1000000;
            }
            else if (right - left + 1 == K) {
                return memo[left][right][k] = sum[right] - sum[left] + s[left];
            }
            return memo[left][right][k] = dp(s, left, right, K, memo) + sum[right] - sum[left] + s[left];
        }
        int min = 1000000;
        for (int i = left; i < right; i++) {
            min = std::min(min, dp(s, left, i, 1, memo) + dp(s, i + 1, right, k - 1, memo));
        }
        return memo[left][right][k] = min;
    }
};


//9:05 9:18 TLE

class Solution {
public:
    int K;
    int mergeStones(vector<int>& stones, int K) {
        if (stones.size() == 0 || stones.size() == 1) {
            return 0;
        }
        unordered_map<string, int> memo;
        this->K = K;
        int r = dp(stones, memo);
        if (r > 1000000) {
            return -1;
        }
        return r;
    }
    int dp(vector<int> s, unordered_map<string, int>& memo) {
        string sig;
        for (auto& x : s) {
            sig += x + '-';
        }
        if (memo.count(sig) > 0) {
            return memo[sig];
        }
        if (s.size() < K) {
            return memo[sig] = 10000000;
        }
        if (s.size() == K) {
            int sum = 0;
            for (int j = 0; j < K; j++) {
                sum += s[j];
            }
            return memo[sig] = sum;
        }
        int min = 10000000;
        for (int i = 0; i < s.size() - K + 1; i++) {
            int sum = 0;
            for (int j = i; j < i + K; j++) {
                sum += s[j];
            }
            auto left = vector<int>(s.cbegin(), s.cbegin() + i);
            left.push_back(sum);
            left.insert(left.end(), s.cbegin() + i + K, s.cend());
            min = std::min(min, sum + dp(move(left), memo));
        }
        return memo[sig] = min;
    }
};