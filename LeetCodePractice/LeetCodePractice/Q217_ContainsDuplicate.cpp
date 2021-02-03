#include<vector>
#include<unordered_set>
using namespace std;
//11:30 11: 33

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> k(nums.cbegin(), nums.cend());
        return k.size() != nums.size();
    }
};