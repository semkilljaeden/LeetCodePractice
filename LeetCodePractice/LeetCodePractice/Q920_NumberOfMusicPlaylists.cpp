#include "LCHeader.h"
class Solution {
public:
    const int base = 1e9 + 7;
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long>> memo(L + 1, vector<long>(N + 1, 0));
        memo[L][N] = 1;
        for (int i = L - 1; i >= 0; i--) {
            for (int j = N - 1; j >= 0; j--) {
                memo[i][j] += memo[i + 1][j + 1] * (N - j);
                memo[i][j] += memo[i + 1][j] * max(j - K, 0);
                memo[i][j] %= base;
            }
        }
        return memo[0][0];
    }
};

class Solution {
public:
    int N;
    int L;
    int K;
    const int base = 1e9 + 7;
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long>> memo(L + 1, vector<long>(N + 1, -1));
        this->N = N;
        this->K = K;
        this->L = L;
        return dp(0, 0, memo);
    }

    long dp(int idx, int count, vector<vector<long>>& memo) {
        if (idx == L) {
            return count == N ? 1 : 0;
        }
        if (count > N) {
            return 0;
        }
        if (memo[idx][count] != -1) {
            return memo[idx][count];
        }
        long sum = dp(idx + 1, count + 1, memo) * (N - count);
        sum += dp(idx + 1, count, memo) * max(count - K, 0);
        sum %= base;
        return memo[idx][count] = sum;
    }
};




//12:30 TLE

class Solution {
public:
    int N;
    int L;
    int K;
    int numMusicPlaylists(int N, int L, int K) {
        vector<int> played(N + 1, 0);
        unordered_map<string, int> memo;
        this->N = N;
        this->K = K;
        this->L = L;
        return dp(0, played, memo);
    }

    int dp(int idx, vector<int> played, unordered_map<string, int>& memo) {
        string key = to_string(idx) + " ";
        for (auto& x : played) {
            key += to_string(x) + ' ';
        }
        if (memo.count(key) > 0) {
            return memo[key];
        }
        if (idx == L) {
            for (int j = 0; j < N; j++) {
                if (played[j] == 0) {
                    return memo[key] = 0;
                }
            }
            return memo[key] = 1;
        }
        int sum = 0;
        for (int i = 0; i < N; i++) {
            if (played[i] > 1) {
                continue;
            }
            auto np = played;
            np[i] = 1 + K;
            for (int j = 0; j < N; j++) {
                if (i == j || np[j] == 1 || np[j] == 0) {
                    continue;
                }
                np[j]--;
            }
            sum += dp(idx + 1, np, memo);

        }
        return memo[key] = sum;
    }
};