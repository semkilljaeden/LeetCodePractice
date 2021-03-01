#include "LCHeader.h"

//8:55 9:02
/*
Runtime: 60 ms, faster than 98.43% of C++ online submissions for Longest Turbulent Subarray.
Memory Usage: 40.3 MB, less than 63.09% of C++ online submissions for Longest Turbulent Subarray.
*/
class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int max = 1;
        const int n = arr.size();
        int prev = -1;
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && arr[i] > prev) {
                count++;
            }
            else if (i % 2 == 1 && arr[i] < prev) {
                count++;
            }
            else {
                max = std::max(max, count);
                count = 1;
            }
            prev = arr[i];
        }
        max = std::max(max, count);
        prev = INT_MAX;
        count = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0 && arr[i] < prev) {
                count++;
            }
            else if (i % 2 == 1 && arr[i] > prev) {
                count++;
            }
            else {
                max = std::max(max, count);
                count = 1;
            }
            prev = arr[i];
        }
        max = std::max(max, count);
        return max;
    }
};