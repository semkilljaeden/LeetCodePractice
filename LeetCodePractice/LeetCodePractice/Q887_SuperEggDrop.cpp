#include "LCHeader.h"
//11:11
class Solution {
public:
    int superEggDrop(int K, int N) {
        return dp(K, N);
    }
    int dp(int K, int N) {
        if (N <= 1) {
            return 1;
        }
        if (K == 1) {
            return N;
        }
        int min = N;
        int left = 0;
        int right = N - 1;
        int result = N;
        while (left < right) {
            int mid = (right - left) / 2 + left;
            int l = dp(K - 1, mid);
            int r = dp(K, N - mid - 1);
            result = std::min(result, 1 + std::max(l, r));
            if (l == r) {
                return result;
            }
            if (l < r) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return result;
    }
};