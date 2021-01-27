#include<vector>
#include<string>
using namespace std;
//9:07 to 9:37 hard 
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
Memory Usage: 12.2 MB, less than 96.93% of C++ online submissions for Find Minimum in Rotated Sorted Array II.
*/
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        int min = INT_MAX;
        while (left < right)
        {
            mid = left + (right - left) / 2;
            int l = nums[left];
            int r = nums[right];
            int m = nums[mid];
            min = std::min(min, m);
            if (l > r)
            {
                if (m > r)
                {
                    left = mid + 1;
                }
                else
                {
                    right = mid - 1;
                }

            }
            else if (l == r)
            {
                left++;
                right--;
                min = std::min(min, l);
            }
            else
            {
                right = mid - 1;
            }

        }
        return std::min(min, nums[left]);
    }
};