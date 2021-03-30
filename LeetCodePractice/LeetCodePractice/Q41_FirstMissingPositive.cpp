#include<vector>
using namespace std;
class Solution {//12:00 12:22
public:
    int firstMissingPositive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 1;
        }
        int min = INT_MAX;
        int max = -1;
        int count = 0;
        for (auto& x : nums) {
            if (x <= 0) {
                continue;
            }
            count++;
            if (x < min) {
                min = x;
            }
            if (x > max) {
                max = x;
            }
        }
        if (count == 0) {
            return 1;
        }
        int shift = min;
        vector<int> tmp(nums.size(), 0);
        for (auto& x : nums) {
            if (x <= 0) {
                continue;
            }
            if (x - shift >= tmp.size()) {
                continue;
            }
            tmp[x - shift] = x;
        }
        if (tmp[0] > 1) {
            return 1;
        }
        for (int i = 0; i < count; i++) {
            auto& x = tmp[i];
            if (x == 0) {
                return i + shift;
            }
        }
        return tmp[count - 1] + 1;
    }
};