#include "LCHeader.h"


//optimization

/*
Runtime: 96 ms, faster than 80.00% of C++ online submissions for Palindrome Removal.
Memory Usage: 15.6 MB, less than 67.69% of C++ online submissions for Palindrome Removal.
*/

class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        vector<vector<int>> memo(arr.size(), vector<int>(arr.size(), -1));
        return dp(arr, 0, arr.size() - 1, memo);
    }

    int dp(vector<int>& arr, int i, int j, vector<vector<int>>& memo) {

        if (i == j || i > j) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int min = INT_MAX;
        if (arr[i] == arr[j]) {
            min = std::min(min, dp(arr, i + 1, j - 1, memo));
        }
        for (int idx = i + 1; idx < j; idx++) {
            if (arr[idx] == arr[i]) {
                min = std::min(min, dp(arr, i, idx, memo) + dp(arr, idx + 1, j, memo));
            }
        }
        min = std::min(min, 1 + dp(arr, i + 1, j, memo));
        return memo[i][j] = min;
    }
};


//3:43 read the tips 4:31 AC!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
Runtime: 232 ms, faster than 50.77% of C++ online submissions for Palindrome Removal.
Memory Usage: 15.6 MB, less than 58.46% of C++ online submissions for Palindrome Removal.
*/
class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        vector<vector<int>> memo(arr.size(), vector<int>(arr.size(), -1));
        return dp(arr, 0, arr.size() - 1, memo);
    }

    int dp(vector<int>& arr, int i, int j, vector<vector<int>>& memo) {

        if (i == j || i > j) {
            return 1;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int min = INT_MAX;
        if (arr[i] == arr[j]) {
            min = std::min(min, dp(arr, i + 1, j - 1, memo));
        }
        for (int idx = i + 1; idx < j; idx++) {
            if (arr[idx] == arr[i]) {
                min = std::min(min, dp(arr, i, idx, memo) + dp(arr, idx + 1, j, memo));
            }
        }
        for (int idx = j - 1; idx > i; idx--) {
            if (arr[idx] == arr[i]) {
                min = std::min(min, dp(arr, i, idx - 1, memo) + dp(arr, idx, j, memo));
            }
        }
        min = std::min(min, 1 + dp(arr, i + 1, j, memo));
        min = std::min(min, 1 + dp(arr, i, j - 1, memo));
        return memo[i][j] = min;
    }
};