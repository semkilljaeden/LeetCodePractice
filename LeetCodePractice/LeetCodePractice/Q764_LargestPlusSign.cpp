#include "LCHeader.h"
//11:34 11:47 one shot AC
/*
Runtime: 196 ms, faster than 80.06% of C++ online submissions for Largest Plus Sign.
Memory Usage: 60.4 MB, less than 35.89% of C++ online submissions for Largest Plus Sign.
*/
class Solution {
public:
    int orderOfLargestPlusSign(int N, vector<vector<int>>& mines) {
        vector<vector<int>> h(N, vector<int>(N, 0));
        vector<vector<int>> v(N, vector<int>(N, 0));
        vector<vector<int>> g(N, vector<int>(N, 1));
        for (auto& x : mines) {
            g[x[0]][x[1]] = 0;
        }
        for (int i = 0; i < N; i++) {
            int sum = 0;
            for (int j = 0; j < N; j++) {
                if (g[i][j] == 0) {
                    sum = 0;
                    continue;
                }
                sum++;
                h[i][j] = sum;
            }
            sum = 0;
            for (int j = N - 1; j >= 0; j--) {
                if (g[i][j] == 0) {
                    sum = 0;
                    continue;
                }
                sum++;
                h[i][j] = std::min(h[i][j], sum);
            }
        }

        for (int j = 0; j < N; j++) {
            int sum = 0;
            for (int i = 0; i < N; i++) {
                if (g[i][j] == 0) {
                    sum = 0;
                    continue;
                }
                sum++;
                v[i][j] = sum;
            }
            sum = 0;
            for (int i = N - 1; i >= 0; i--) {
                if (g[i][j] == 0) {
                    sum = 0;
                    continue;
                }
                sum++;
                v[i][j] = std::min(v[i][j], sum);
            }
        }
        int max = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                max = std::max(max, std::min(h[i][j], v[i][j]));
            }
        }
        return max;
    }
};