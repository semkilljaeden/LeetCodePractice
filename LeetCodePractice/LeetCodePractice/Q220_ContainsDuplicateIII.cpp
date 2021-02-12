#include<vector>
#include<unordered_map>
#include<set>
using namespace std;
/*
Runtime: 40 ms, faster than 67.48% of C++ online submissions for Contains Duplicate III.
Memory Usage: 15.1 MB, less than 58.88% of C++ online submissions for Contains Duplicate III.
*/
//took very long time to get understand lower_bound and upper_bound and Int max/min cases

class Solution2 {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> bst;
        auto first = nums.cbegin();
        for (auto itr = nums.cbegin(); itr != nums.cend(); itr++)
        {
            long x = *itr;
            auto lower = bst.lower_bound(x - t);
            if (lower != bst.end() && *lower <= x)
            {
                return true;
            }
            auto upper = bst.upper_bound(x);
            if (upper != bst.end() && x + t >= *upper)
            {
                return true;
            }
            bst.insert(x);
            if (bst.size() > k)
            {
                bst.erase(*first++);
            }
        }
        return false;
    }
};

//10:21 10:29 tle
class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        for (auto itr = nums.cbegin(); itr != nums.cend(); itr++)
        {
            for (auto ii = itr + 1; ii != itr + k + 1 && ii != nums.cend(); ii++)
            {
                if (abs((long)*ii - (long)*itr) <= (long)t)
                {
                    return true;
                }
            }
        }
        return false;
    }
};