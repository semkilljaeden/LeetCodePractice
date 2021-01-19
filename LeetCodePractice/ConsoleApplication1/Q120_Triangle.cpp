//1:37 TO 2:26, practicing c++ it is ok, medium
/*
Runtime: 8 ms, faster than 88.66% of C++ online submissions for Triangle.
Memory Usage: 9.3 MB, less than 9.29% of C++ online submissions for Triangle.*/
#include<vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> memo(triangle.size(), vector<int>(triangle.size(), INT_MIN));
        return mini(triangle, 0, 0, memo);
    }

    int mini(vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& memo)
    {
        if (memo[row][col] > INT_MIN)
        {
            return memo[row][col];
        }
        if (row == triangle.size() - 1)
        {
            return memo[row][col] = triangle.back()[col];
        }       
        return memo[row][col] = triangle[row][col] + min(mini(triangle, row + 1, col, memo), mini(triangle, row + 1, col + 1, memo));
    }
};