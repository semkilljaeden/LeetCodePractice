#include<vector>
using namespace std;
//7:31 to 7:54 one shot AC for medium, (not)best solution
/*
Runtime: 4 ms, faster than 95.08% of C++ online submissions for Counting Bits.
Memory Usage: 7.7 MB, less than 96.92% of C++ online submissions for Counting Bits.
*/
class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result(num + 1);
        result[0] = 0;
        for (int i = 1; i < num + 1; i++) {
            int b = (i - 1) & i;
            if (b == i - 1) {
                result[i] = result[i - 1] + 1;
            }
            else if (b > i) {
                result[i] = 1;
            }
            else {
                result[i] = result[i - 1] - static_cast<int>(log2(i - b)) + 1;
            }
        }
        return result;
    }
};