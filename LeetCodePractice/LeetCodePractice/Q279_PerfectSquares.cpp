#include<vector>
#include<unordered_map>
using namespace std;
//6:02, 6:28
/*
untime: 1168 ms, faster than 5.01% of C++ online submissions for Perfect Squares.
Memory Usage: 56.4 MB, less than 5.01% of C++ online submissions for Perfect Squares.
*/
class Solution {
public:
    vector<int> sqn;
    Solution() :sqn(100) {
        for (int i = 1; i <= 100; i++) {
            sqn[i - 1] = i * i;
        }
    }
    int numSquares(int n) {
        unordered_map<int, long> memo;
        for (auto& x : sqn) {
            memo[x] = 1;
        }
        return cal(n, memo);
    }
    long cal(int n, unordered_map<int, long>& memo) {
        if (n < 1) {
            return INT_MAX - 1;
        }
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        long min = INT_MAX;
        for (int i = 0; i < 100; i++) {
            min = std::min(min, cal(n - sqn[i], memo) + 1);
        }
        memo[n] = min;
        return min;
    }
};