#include<vector>
#include<unordered_map>
using namespace std;
//3:50, 4:10, thinking about bitwise too long
/*
* Runtime: 8 ms, faster than 96.12% of C++ online submissions for Single Number II.
Memory Usage: 10.1 MB, less than 24.67% of C++ online submissions for Single Number II.
Next challenges:
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int& x : nums)
        {
            if (map.find(x) == map.end())
            {
                map[x] = 1;
            }
            else
            {
                map[x]++;
            }
        }
        for (auto& p : map)
        {
            if (p.second == 1)
            {
                return p.first;
            }
        }
        return -1;
    }
};