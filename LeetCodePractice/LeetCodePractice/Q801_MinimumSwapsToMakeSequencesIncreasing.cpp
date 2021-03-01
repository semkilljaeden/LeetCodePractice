#include "LCHeader.h"
//1:19 1:40 21mins AC
class Solution {
public:
    int minSwap(vector<int>& A, vector<int>& B) {
        vector<vector<int>> memo(A.size(), vector<int>(2, -1));
        return min(1 + dp(A, B, 1, 1, memo), dp(A, B, 1, 0, memo));
    }

    int dp(vector<int>& A, vector<int>& B, int pos, int swaped, vector<vector<int>>& memo) {
        if (pos == A.size()) {
            return 0;
        }
        if (memo[pos][swaped] != -1) {
            return memo[pos][swaped];
        }
        int result = 100000000;
        int pa = A[pos - 1];
        int pb = B[pos - 1];
        int ca = A[pos];
        int cb = B[pos];
        if (swaped == 1) {
            swap(pa, pb);
        }
        if (ca > pa && cb > pb) {
            result = std::min(result, dp(A, B, pos + 1, 0, memo));
            swap(ca, cb);
            if (ca > pa && cb > pb) {
                result = std::min(result, 1 + dp(A, B, pos + 1, 1, memo));
            }
        }
        else {
            swap(ca, cb);
            if (ca > pa && cb > pb) {
                result = std::min(result, 1 + dp(A, B, pos + 1, 1, memo));
            }
        }
        return memo[pos][swaped] = result;
    }
};