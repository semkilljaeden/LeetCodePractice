#include "LCHeader.h"
//3:28 3:35 3:41
/*
Runtime: 4 ms, faster than 100.00% of C++ online submissions for Largest Sum of Averages.
Memory Usage: 8 MB, less than 62.21% of C++ online submissions for Largest Sum of Averages.
*/
class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int K) {
        vector<vector<double>> memo(A.size() + 1, vector<double>(K + 1, -1.0));
        return dp(A, K, 0, memo);
    }

    double dp(vector<int>& A, int K, int pos, vector<vector<double>>& memo) {
        if (memo[pos][K] + 1.0 > 0.000000001) {
            return memo[pos][K];
        }
        if (K == 1) {
            double sum = 0;
            for (int i = pos; i < A.size(); i++) {
                sum += A[i];
            }
            return memo[pos][K] = sum / (A.size() - pos);
        }
        double result = INT_MIN;
        double sum = 0;
        for (int i = pos; i < A.size() - K + 1; i++) {
            sum += A[i];
            result = std::max(result, sum / (i - pos + 1) + dp(A, K - 1, i + 1, memo));
        }
        return memo[pos][K] = result;
    }
};