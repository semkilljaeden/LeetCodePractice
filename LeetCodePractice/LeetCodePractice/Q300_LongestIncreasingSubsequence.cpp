#include<vector>
#include<set>
using namespace std;



//12:59 to 1:08

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        set<int> tree;
        tree.insert(nums[0]);
        size_t result = 1;
        for (auto itr = ++nums.cbegin(); itr != nums.cend(); itr++) {
            auto x = tree.lower_bound(*itr);
            if (x == tree.end()) {
                tree.insert(*itr);
            }
            else {
                tree.erase(x);
                tree.insert(*itr);
            }
            result = std::max(result, tree.size());
        }
        return result;
    }
};

//O(N^2)

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> memo(nums.size(), 0);
        memo[0] = 1;
        int result = 1;
        for (int i = 1; i < nums.size(); i++) {
            int max = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    max = std::max(max, memo[j] + 1);
                }
            }
            result = std::max(result, memo[i] = max);
        }
        return result;
    }
};