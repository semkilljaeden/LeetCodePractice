#include<vector>
using namespace std;
//1mins
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int result = 0;
        for (int i = 0; i < 32; i++)
        {
            if ((n | 1 << i) == n)
            {
                result++;
            }
        }
        return result;
    }
};