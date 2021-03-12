#include "LCHeader.h"


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::less<int>());
        int count = 0;

        for (int i = nums.size() - 1; i >= 0; i--) {
            int j = 0;
            int k = i - 1;
            while (j < k) {
                if (nums[j] + nums[k] > nums[i]) {
                    count += k - j;
                    k--;
                }
                else if (nums[j] + nums[k] <= nums[i]) {
                    j++;
                }
            }
        }
        return count;
    }
};


class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), std::less<int>());
        unordered_map<int, int> map;
        int count = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                auto index = lower_bound(nums.begin() + j + 1, nums.end(), nums[i] + nums[j]) - nums.begin();
                int tmp = index - j - 1;
                count += tmp > 0 ? tmp : 0;
            }
        }
        return count;
    }
};


//2:48 3:00 TLE
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[i] == 0 || nums[j] == 0) {
                    continue;
                }
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[k] != 0 && nums[k] < nums[i] + nums[j] && nums[i] < nums[k] + nums[j] && nums[j] < nums[i] + nums[k]) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};