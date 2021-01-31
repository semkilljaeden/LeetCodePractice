#include<vector>
using namespace std;

//5:31 to 5:46 15mins for an easy, no so fast
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Bits.
Memory Usage: 5.8 MB, less than 98.01% of C++ online submissions for Reverse Bits.
*/
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int right = 0;
        int left = 0;
        int mask = 0;
        for (int i = 0; i < 16; i++)
        {
            right = 1 << i;
            left = 1 << 31 - i;
            mask = left + right;
            if (n == (mask | n))
            {
                continue;
            }
            if (n == (left | n))
            {
                n -= left;
                n += right;
                continue;
            }
            if (n == (right | n))
            {
                n -= right;
                n += left;
                continue;
            }
        }
        return n;
    }
};