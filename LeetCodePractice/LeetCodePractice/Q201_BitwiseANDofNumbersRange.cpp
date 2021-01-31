#include<vector>
//3:42 4: 23, interruppted, should be finished within 30mins
/*
Runtime: 8 ms, faster than 71.05% of C++ online submissions for Bitwise AND of Numbers Range.
Memory Usage: 5.9 MB, less than 76.11% of C++ online submissions for Bitwise AND of Numbers Range.
*/
class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int result = 0;
        int tmp = 0;
        int i = 30;
        while (i >= 0 && ((tmp & m) == (tmp & n)))
        {
            result = (tmp & m);
            tmp += (1 << i--);
        }
        result = (tmp & m);
        return result;
    }
};