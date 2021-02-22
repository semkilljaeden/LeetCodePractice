#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//12:51 12:58 omfg i am amazing
/*
Runtime: 20 ms, faster than 39.25% of C++ online submissions for 2 Keys Keyboard.
Memory Usage: 5.9 MB, less than 90.19% of C++ online submissions for 2 Keys Keyboard.
*/
class Solution {
public:
    int n;
    int minSteps(int n) {
        this->n = n;
        if (n < 2) {
            return 0;
        }
        return 1 + dp(1, 1);
    }

    long dp(int copy, int length) {
        if (length > n) {
            return INT_MAX;
        }
        if (length == n) {
            return 0;
        }
        long min = INT_MAX;
        min = std::min(min, 1 + dp(copy, length + copy));
        min = std::min(min, 2 + dp(length, length + length));
        return min;
    }
};