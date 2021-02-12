#include<vector>
#include<unordered_map>
using namespace std;
//5mins
/*
Runtime: 20 ms, faster than 97.79% of C++ online submissions for Contains Duplicate II.
Memory Usage: 16.7 MB, less than 68.42% of C++ online submissions for Contains Duplicate II.
*/
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        int i = 0;
        for (auto& x : nums)
        {
            if (map.find(x) != map.cend() && i - map[x] <= k)
            {
                return true;
            }
            map[x] = i;
            i++;
        }
        return false;
    }
};