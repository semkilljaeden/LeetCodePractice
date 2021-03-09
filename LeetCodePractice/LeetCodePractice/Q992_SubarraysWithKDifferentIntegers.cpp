#include "LCHeader.h"

//1:35 2:52 read the answer
/*
Runtime: 144 ms, faster than 60.74% of C++ online submissions for Subarrays with K Different Integers.
Memory Usage: 46.4 MB, less than 33.27% of C++ online submissions for Subarrays with K Different Integers.
*/

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return helper(A, K) - helper(A, K - 1);
    }

    int helper(vector<int>& A, int K) {
        unordered_map<int, int> set;
        int left = 0;
        int right = 0;
        int count = 0;
        for (; right < A.size(); right++) {
            set[A[right]]++;
            if (set.size() > K) {
                while (set.size() > K) {
                    set[A[left]]--;
                    if (set[A[left]] == 0) {
                        set.erase(A[left]);
                    }
                    left++;
                }
            }
            count += right - left + 1;
        }
        return count;
    }
};