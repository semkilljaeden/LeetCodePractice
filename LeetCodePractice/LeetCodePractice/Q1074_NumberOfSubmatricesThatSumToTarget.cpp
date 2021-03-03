#include "LCHeader.h"
//8:36 9:06 30mins, AC!!!!! O(MN^2) yeah!!!!!
/*
Runtime: 556 ms, faster than 82.25% of C++ online submissions for Number of Submatrices That Sum to Target.
Memory Usage: 118.5 MB, less than 59.24% of C++ online submissions for Number of Submatrices That Sum to Target.
*/
class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<vector<int>>> memo(m, vector<vector<int>>(n, vector<int>(n, 0)));
        vector<int> sum(n, 0);
        for (int k = 0; k < m; k++) {
            auto& x = matrix[k];
            int prev = 0;
            for (int i = 0; i < n; i++) {
                sum[i] = prev + x[i];
                prev = sum[i];
            }
            for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                    memo[k][i][j] = sum[j] - sum[i] + x[i];
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int sum = 0;
                unordered_map<int, int> map;
                for (int k = 0; k < m; k++) {
                    sum += memo[k][i][j];
                    if (sum == target) {
                        count++;
                    }
                    if (map.count(sum - target) > 0) {
                        count += map[sum - target];
                    }
                    map[sum]++;
                }
            }
        }
        return count;
    }
};