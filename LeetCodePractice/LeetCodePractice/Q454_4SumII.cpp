#include "LCHeader.h"
//12:55 1:00
//too easy
/*
Runtime: 156 ms, faster than 96.43% of C++ online submissions for 4Sum II.
Memory Usage: 29.3 MB, less than 83.27% of C++ online submissions for 4Sum II.
*/
class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> count;
        for (int i = 0; i < C.size(); i++) {
            for (int j = 0; j < D.size(); j++) {
                count[C[i] + D[j]]++;
            }
        }
        int result = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < B.size(); j++) {
                if (count.count(-(A[i] + B[j])) > 0) {
                    result += count[-(A[i] + B[j])];
                }
            }
        }
        return result;
    }
};