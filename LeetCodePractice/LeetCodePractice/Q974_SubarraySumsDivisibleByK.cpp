#include "LCHeader.h"
//6:55
/*
Runtime: 28 ms, faster than 99.84% of C++ online submissions for Subarray Sums Divisible by K.
Memory Usage: 30.2 MB, less than 84.22% of C++ online submissions for Subarray Sums Divisible by K.
*/
class Solution {//6:47
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int prev = 0;
        vector<int> map(K + 1, 0);
        map[0] = 1;
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            int sum = prev + A[i];
            prev = sum;
            int reminder = sum % K;
            if (reminder < 0) {
                reminder += K;
            }
            count += map[reminder];
            map[reminder]++;
        }
        return count;
    }
};