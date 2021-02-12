#include<vector>
#include<memory>
using namespace std;


class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> memo1(nums1.size() + 1, vector<int>());
        vector<vector<int>> memo2(nums2.size() + 1, vector<int>());
        dp(nums1, k, memo1);
        dp(nums2, k, memo2);
        return vector<int>();
    }

    void dp(vector<int>& n, int k, vector<vector<int>>& memo) {
        vector<vector<int>> tmp(memo.size());

        for (int j = 1; j <= k; j++) {
            for (int i = n.size() - 1; i >= 0; i--) {
                tmp[i] = memo[i + 1];
                tmp[i].insert(tmp[i].begin(), n[i]);
                max(tmp[i], tmp[i + 1]);
            }
            memo = tmp;
        }
        return;
    }

    void max(vector<int>& left, vector<int>& right) {
        if (right.size() < left.size()) {
            return;
        }
        for (int i = 0; i < right.size(); i++) {
            if (left[i] < right[i]) {
                left = right;
                return ;
            }
            else if (right[i] < left[i]) {
                return;
            }
        }
    }
};



//11:24 12:25 failed, does not work for a long number, damn it actually works. vector copy is still required
//we just need to use dp to find best number independently, then merge them togather. wtf
//TLE O(mnk^2)

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<vector<vector<int>>>> memo(nums1.size() + 1, vector<vector<vector<int>>>(nums2.size() + 1,
            vector<vector<int>>(k + 1, vector<int>())));
        vector<int> result = dp(nums1, nums2, k, 0, 0, memo);
        reverse(result.begin(), result.end());
        return result;
    }

    vector<int> dp(vector<int>& nums1, vector<int>& nums2, int k, int i, int j, vector<vector<vector<vector<int>>>>& memo) {
        if (i >= nums1.size() && j >= nums2.size() || k > (nums1.size() - i) + (nums2.size() - j) || k <= 0) {
            return vector<int>();
        }
        if (memo[i][j][k - 1].size() != 0) {
            return memo[i][j][k - 1];
        }
        vector<int> tmp(k, INT_MIN);
        if (i < nums1.size()) {
            tmp = Solution::max(tmp, dp(nums1, nums2, k, i + 1, j, memo));
            tmp = Solution::max(tmp, dp(nums1, nums2, k - 1, i + 1, j, memo), nums1[i]);
        }
        if (j < nums2.size()) {
        tmp = Solution::max(tmp, dp(nums1, nums2, k, i, j + 1, memo));
        tmp = Solution::max(tmp, dp(nums1, nums2, k - 1, i, j + 1, memo), nums2[j]);
        }
        if (i < nums1.size() && j < nums2.size()) {
            tmp = Solution::max(tmp, dp(nums1, nums2, k, i + 1, j + 1, memo));
        }
    return memo[i][j][k - 1] = tmp;
}

vector<int> max(vector<int>& left, vector<int>&& right) {
    for (int i = 0; i < right.size(); i++) {
        if (left[i] < right[i]) {
            return right;
        }
        else if (right[i] < left[i]) {
            return left;
        }
    }
    return left;
}

vector<int> max(vector<int>& left, vector<int>&& right, int last) {
    right.insert(right.begin(), last);
    for (int i = 0; i < right.size(); i++) {
        if (left[i] < right[i]) {
            return right;
        }
        else if (right[i] < left[i]) {
            return left;
        }
    }
    return left;
}
};