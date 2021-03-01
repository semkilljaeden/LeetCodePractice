#include "LCHeader.h"
//6:52

class Solution {
public:
    int N;
    int K;
    int W;
    double new21Game(int N, int K, int W) {
        if (K == 0) {
            return 1;
        }
        this->N = N;
        this->K = K;
        this->W = W;
        vector<double> memo(K + W, 0);
        double sum = 0;
        for (int j = K; j <= K + W - 1; j++) {
            sum += memo[j] = j <= N ? 1 : 0;
        }
        for (int i = K - 1; i >= 0; i--) {
            memo[i] = sum / W;
            sum += memo[i];
            sum -= memo[i + W];
        }
        return memo[0];
    }

    double new21Game2(int N, int K, int W) {
        if (K == 0) {
            return 1;
        }
        this->N = N;
        this->K = K;
        this->W = W;
        vector<double> memo(K, 0);
        for (int i = K - 1; i >= 0; i--) {
            for (int j = 1; j <= W; j++) {
                if (i + j >= K) {
                    memo[i] += (i + j) <= N ? 1 : 0;
                }
                else {
                    memo[i] += memo[i + j];
                }
            }
            memo[i] /= W;
        }
        return memo[0];
    }


    double dp(int k, vector<double>& memo) {
        if (k >= K) {
            return k <= N ? 1 : 0;
        }
        if (memo[k] != -1) {
            return memo[k];
        }
        memo[k] = 0;
        for (int i = 1; i <= W; i++) {
            memo[k] += dp(k + i, memo) / W;
        }
        return memo[k];
    }
};