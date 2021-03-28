#include<vector>
using namespace std;

class Solution {//4:20 4:27
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return 0;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> memo(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == '1') {
                    count++;
                }
                else {
                    count = 0;
                }
                memo[i][j] = count;
            }
        }
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] != '1') {
                    continue;
                }
                int col = 1;
                int row = INT_MAX;
                for (int k = i; k >= 0; k--) {
                    if (matrix[k][j] == '0') {
                        break;
                    }
                    row = std::min(row, memo[k][j]);
                    result = std::max(result, row * col);
                    col++;
                }
            }
        }
        return result;
    }
};