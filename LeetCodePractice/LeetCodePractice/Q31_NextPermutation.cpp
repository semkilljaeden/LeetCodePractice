#include "LCHeader.h"

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for (int i = nums.size() - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                int pos = i + 1;
                while (pos < nums.size() && nums[i] < nums[pos]) {
                    pos++;
                }
                pos--;
                swap(nums[i], nums[pos]);
                sort(nums.begin() + i + 1, nums.end());
                return;
            }
        }
        sort(nums.begin(), nums.end());
    }
};



class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int left = -1;
        int right = -1;
        int prev = -1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (nums[i] < prev) {
                left = i;
                for (int j = left + 1; j < nums.size(); j++) {
                    if (nums[j] <= nums[left]) {
                        break;
                    }
                    right = j;
                }
                break;
            }
            prev = nums[i];

        }
        if (left == -1) {
            sort(nums.begin(), nums.end(), std::less<char>());
        }
        else {
            swap(nums[left], nums[right]);
            sort(nums.begin() + left + 1, nums.end(), std::less<char>());
        }
    }
};