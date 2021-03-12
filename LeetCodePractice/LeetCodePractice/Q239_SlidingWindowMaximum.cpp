#include "LCHeader.h"
#include <queue>


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int, int>> dq;
        int j = 0;
        while (j < k) {
            while (dq.size() > 0 && dq.back().first < nums[j]) {
                dq.pop_back();
            }
            dq.push_back(make_pair(nums[j], j));
            j++;
        }
        int i = 0;
        vector<int> result;
        result.reserve(nums.size() - k);
        result.push_back(dq.front().first);
        for (; j < nums.size(); j++) {
            int& y = nums[j];
            while (dq.size() > 0 && dq.front().second <= i) {
                dq.pop_front();
            }
            while (dq.size() > 0 && dq.back().first < y) {
                dq.pop_back();
            }
            dq.push_back(make_pair(y, j));
            result.push_back(dq.front().first);
            i++;
        }
        return result;
    }
};

//3:11 3:24 not the best solution but still O(nlogn)
/*
Runtime: 480 ms, faster than 29.19% of C++ online submissions for Sliding Window Maximum.
Memory Usage: 166.4 MB, less than 14.22% of C++ online submissions for Sliding Window Maximum.
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, std::less<int>> pq;
        unordered_map<int, int> contains;
        int j = 0;
        while (j < k) {
            pq.push(nums[j]);
            contains[nums[j]]++;
            j++;
        }
        int i = 0;
        vector<int> result;
        result.reserve(nums.size() - k);
        result.push_back(pq.top());
        for (; j < nums.size(); j++) {
            int& x = nums[i];
            int& y = nums[j];
            contains[x]--;
            if (contains[x] == 0) {
                contains.erase(x);
            }
            pq.push(y);
            contains[y]++;
            while (contains.count(pq.top()) == 0) {
                pq.pop();
            }
            result.push_back(pq.top());
            i++;
        }
        return result;
    }
};