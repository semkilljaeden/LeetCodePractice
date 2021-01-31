#include<vector>
#include<string>
using namespace std;
//4:11 5:28 read the answer, stupid for a medium
/*
Runtime: 4 ms, faster than 93.17% of C++ online submissions for Rotate Array.
Memory Usage: 9.9 MB, less than 78.81% of C++ online submissions for Rotate Array.
*/
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k %= nums.size();
        if (k == 0)
        {
            return;
        }
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() += k);
        reverse(nums.begin() += k, nums.end());
        return;
    }

};