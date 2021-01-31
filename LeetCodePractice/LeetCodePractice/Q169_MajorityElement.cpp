#include<vector>
#include<string>
using namespace std;
//11:17 to 33, read the solution to learn O(1) space solution
/*
Runtime: 8 ms, faster than 99.90% of C++ online submissions for Majority Element.
Memory Usage: 19.6 MB, less than 85.17% of C++ online submissions for Majority Element.
Next challenges:
*/
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c = 0;
        int n = 1;
        for (const int& x : nums)
        {
            if (x != c)
            {
                if (--n <= 0)
                {
                    c = x;
                    n = 1;
                }
            }
            else
            {
                n++;
            }
        }
        return c;
    }
};