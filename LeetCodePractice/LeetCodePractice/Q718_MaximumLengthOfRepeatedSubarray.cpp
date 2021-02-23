#include<vector>
using namespace std;
//10:30 10:44, silly bug

class Solution {
public:
    int findLength(vector<int>& A, vector<int>& B) {
        vector<vector<int>> memo(A.size() + 1, vector<int>(B.size() + 1, -1));
        int max = 0;
        dp(A, B, 0, 0, memo);
        for (int i = 0; i < memo.size(); i++) {
            for (int j = 0; j < memo[1].size(); j++) {
                if (memo[i][j] > max) {
                    max = memo[i][j];
                }
            }
        }
        return max;
    }

    int dp(vector<int>& A, vector<int>& B, int i, int j, vector<vector<int>>& memo) {
        if (i == A.size() || j == B.size()) {
            return 0;
        }
        if (memo[i][j] != -1) {
            return memo[i][j];
        }
        int max = 0;
        memo[i][j] = 0;
        dp(A, B, i + 1, j, memo);
        dp(A, B, i, j + 1, memo);
        if (A[i] == B[j]) {
            memo[i][j] = 1 + dp(A, B, i + 1, j + 1, memo);
        }
        return memo[i][j];
    }
};