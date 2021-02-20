#include<vector>
#include<unordered_map>
using namespace std;
//9:02  9:44 fucking idiot 0 boundary case

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> map;
        map[0] = -1;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            int tmp = sum;
            if (k != 0) {
                tmp %= k;
            }
            if (map.count(tmp) > 0) {
                if (map[tmp] + 1 < i) {
                    return true;
                }
            }
            else {
                map[tmp] = i;
            }

        }
        return false;
    }
};