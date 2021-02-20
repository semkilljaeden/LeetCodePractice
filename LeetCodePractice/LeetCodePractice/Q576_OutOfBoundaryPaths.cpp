#include<vector>
using namespace std;
//need to mention can do memory optimization in forward dp on N since N is only one step, 
//3:37 3:56 easy, modulo arithmetic
/*
Runtime: 8 ms, faster than 80.47% of C++ online submissions for Out of Boundary Paths.
Memory Usage: 9.6 MB, less than 44.44% of C++ online submissions for Out of Boundary Paths.
*/
class Solution {
public:
    vector<vector<vector<int>>> memo;
    int base = pow(10, 9) + 7;
    int findPaths(int m, int n, int N, int i, int j) {
        memo = vector<vector<vector<int>>>(m + 1, vector<vector<int>>(n + 1, vector<int>(N + 1, -1)));
        return dp(m, n, N, i, j) % base;
    }

    int dp(int& m, int& n, int N, int i, int j) {
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return N >= 0 ? 1 : 0;
        }
        if (N <= 0) {
            return 0;
        }
        if (memo[i][j][N] != -1) {
            return memo[i][j][N];
        }
        int sum = 0;
        sum += dp(m, n, N - 1, i + 1, j);
        sum %= base;
        sum += dp(m, n, N - 1, i, j + 1);
        sum %= base;
        sum += dp(m, n, N - 1, i - 1, j);
        sum %= base;
        sum += dp(m, n, N - 1, i, j - 1);
        sum %= base;
        return memo[i][j][N] = sum % base;
    }
};