#include<vector>
using namespace std;
//6:51 to 7:02
/*
Runtime: 8 ms, faster than 100.00% of C++ online submissions for Range Sum Query 2D - Immutable.
Memory Usage: 15.4 MB, less than 73.37% of C++ online submissions for Range Sum Query 2D - Immutable.
*/
class NumMatrix {
public:
    vector<vector<int>> local;
    NumMatrix(vector<vector<int>>& matrix) : local(matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        int m = matrix.size();
        int n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int sum = 0;
            for (int j = 0; j < n; j++) {
                sum += matrix[i][j];
                local[i][j] = i - 1 < 0 ? 0 : local[i - 1][j];
                local[i][j] += sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int r = local[row2][col2];
        r -= col1 - 1 < 0 ? 0 : local[row2][col1 - 1];
        r -= row1 - 1 < 0 ? 0 : local[row1 - 1][col2];
        r += col1 - 1 < 0 || row1 - 1 < 0 ? 0 : local[row1 - 1][col1 - 1];
        return r;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */