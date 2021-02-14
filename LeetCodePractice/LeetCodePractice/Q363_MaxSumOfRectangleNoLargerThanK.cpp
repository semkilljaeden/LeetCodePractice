#include<vector>
#include<set>
using namespace std;
//6:00 to 6:26 O(m*n^2*log(m))
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        int max = INT_MIN;
        for (int j = 1; j <= n; j++) {
            for (int h = 1; h <= j; h++) {
                set<int> bt;
                memo[1][j] = memo[0][j] + memo[1][j - 1] - memo[0][j - 1] + matrix[0][j - 1];
                int tmp = memo[1][j] - memo[1][h - 1];
                bt.insert(tmp);
                if (tmp <= k) {
                    if (tmp == k) {
                        return k;
                    }
                    max = std::max(max, tmp);
                }
                bt.insert(0);
                for (int i = 2; i <= m; i++) {
                    memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + matrix[i - 1][j - 1];
                    tmp = memo[i][j] - memo[i][h - 1];
                    bt.insert(tmp);
                    auto itr = bt.lower_bound(tmp - k);
                    if (itr != bt.end()) {
                        int x = tmp - *itr;
                        if (x == k) {
                            return k;
                        }
                        else if (x < k) {
                            max = std::max(max, tmp - *itr);
                        }
                    }
                }
            }
        }
        return max;
    }
};
//11:21 11:52 read the question wrongly

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        int max = 0;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                memo[i][j] = memo[i - 1][j] + memo[i][j - 1] - memo[i - 1][j - 1] + matrix[i - 1][j - 1];
                int can = matrix[i - 1][j - 1];
                if (can <= k) {
                    max = std::max(max, can);
                }
                for (int x = 1; x < min(i, j); x++) {
                    can = memo[i][j] - memo[i - x - 1][j] - memo[i][j - x - 1] + memo[i - x - 1][j - x - 1];
                    if (can <= k) {
                        max = std::max(max, can);
                    }
                }
            }
        }
        return max;
    }
};