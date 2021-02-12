#include<vector>
using namespace std;
//4:09 to 5:08, using int in char makes overflow problem, resulint debugging to long. too slow for medium
/*
Runtime: 20 ms, faster than 96.94% of C++ online submissions for Maximal Square.
Memory Usage: 11.5 MB, less than 65.71% of C++ online submissions for Maximal Square.
*/
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int max = 0;
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i < m + 1; i++) {
            for (int j = 1; j < n + 1; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    max = std::max(max, memo[i][j] = min(memo[i - 1][j], min(memo[i][j - 1], memo[i - 1][j - 1])) + 1);
                }
            }
        }
        return max * max;
    }
};