#include<vector>
#include<string>
using namespace std;
//1:37 2:47, miss read the question, making corner case really hard to maintain

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> result;
        if (nums.size() == 0)
        {
            result.push_back(build(lower, upper));
            return result;
        }
        if (nums[0] > lower)
        {
            result.push_back(build(lower, nums[0] - 1));
        }
        for (int i = 1; i < nums.size() && nums[i] <= upper; i++)
        {
            if (nums[i] - nums[i - 1] > 1) {
                result.push_back(build(nums[i - 1] + 1, nums[i] - 1));
            }
        }
        if (nums.back() < upper)
        {
            result.push_back(build(nums.back() + 1, upper));
        }
        return result;
    }

    string build(int lower, int upper) {
        if (lower == upper) {
            return to_string(lower);
        }
        else {
            return to_string(lower) + "->" + to_string(upper);
        }
    }
};