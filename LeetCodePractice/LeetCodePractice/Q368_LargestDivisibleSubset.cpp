#include<vector>
#include<set>
#include<algorithm>
using namespace std;
//8:06,read the answer
class Solution {
public:
    set<int> s;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        if (nums.size() == 0) {
            return vector<int>();
        }
        sort(nums.begin(), nums.end(), [](int& a, int& b) {return a < b; });
        vector<vector<int>> memo;
        memo.push_back(vector<int>{nums[0]});
        int max = 1;
        int c = 0;
        for (auto itr = ++nums.cbegin(); itr != nums.cend(); itr++) {
            int count = 0;
            int tc = -1;
            int tmax = 0;
            for (int i = memo.size() - 1; i >= 0; i--) {
                if (*itr % memo[i].back() == 0 && memo[i].size() > tmax) {
                    tmax = memo[i].size();
                    tc = i;
                }
            }
            if (tc == -1) {
                memo.push_back(vector<int>{*itr});
            }
            else {
                memo.push_back(memo[tc]);
                memo.back().push_back(*itr);
            }
            if (memo.back().size() > max) {
                max = memo.back().size();
                c = memo.size() - 1;
            }
        }
        return memo[c];
    }

};
//6:29 7:52 TLE
class Solution {
public:
    set<int> s;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return a < b;
        });
        set<int> r;
        dp(0, nums, r);
        vector<int> result(s.cbegin(), s.cend());
        return result;
    }

    void dp(int i, vector<int>& nums, set<int> result) {
        if (i >= nums.size()) {
            return;
        }
        if (result.size() == 0) {
            result.insert(nums[i]);
            if (result.size() > s.size()) {
                s = result;
            }
            dp(i + 1, nums, result);
            return;
        }
        if (nums[i] % *result.rbegin() == 0) {
            result.insert(nums[i]);
            if (result.size() > s.size()) {
                s = result;
            }
            dp(i + 1, nums, result);
        }
        else {
            dp(i + 1, nums, result);
            set<int> copy = result;
            auto itr = --copy.end();
            while (nums[i] % *itr != 0) {
                if (copy.size() == 0 || itr == copy.begin()) {
                    copy.erase(itr--);
                    break;
                }
                else {
                    copy.erase(itr--);
                }
            }
            copy.insert(nums[i]);
            dp(i + 1, nums, copy);
        }
    }
};