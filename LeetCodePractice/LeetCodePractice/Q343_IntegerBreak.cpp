#include<vector>
using namespace std;

//8:00 to 8:12
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Integer Break.
Memory Usage: 6.1 MB, less than 73.39% of C++ online submissions for Integer Break.
*/
class Solution {
public:
    int integerBreak(int n) {
        vector<int> memo(n < 3 ? 4 : n + 1);
        memo[0] = 0;
        memo[1] = 1;
        memo[2] = 1;
        memo[3] = 2;
        if (n <= 3) {
            return memo[n];
        }
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j <= i / 2; j++) {
                memo[i] = std::max(memo[i - j] * memo[j], memo[i]);
                memo[i] = std::max(memo[i - j] * (j), memo[i]);
                memo[i] = std::max((i - j) * memo[j], memo[i]);
                memo[i] = std::max((i - j) * j, memo[i]);
            }
        }
        return memo[n];

    }


};