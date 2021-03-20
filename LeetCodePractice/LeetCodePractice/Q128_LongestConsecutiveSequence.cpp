#include<vector>
#include<unordered_map>
#include<memory>
#include<cmath>
#include<algorithm>
using namespace std;




class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int l = 0;
        int r = 1;
        int prev = nums[0];
        int max = 1;
        int tmp = 1;
        for (; r < nums.size(); r++) {
            if (nums[r] == prev) {

            }
            else if (nums[r] - prev != 1) {
                max = std::max(max, tmp);
                l = r;
                tmp = 1;
            }
            else if (nums[r] - prev == 1) {
                tmp++;
            }
            prev = nums[r];
        }
        max = std::max(max, tmp);
        return max;
    }
};


//11:35 to 12:08. best O(1) solution
/*
Runtime: 12 ms, faster than 94.49% of C++ online submissions for Longest Consecutive Sequence.
Memory Usage: 11.1 MB, less than 55.33% of C++ online submissions for Longest Consecutive Sequence.
*/
class Solution {
public:
    struct X
    {
        int head;
        int tail;
    };
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, shared_ptr<X>> head;
        unordered_map<int, shared_ptr<X>> tail;
        for (auto x : nums)
        {
            if (head.find(x) != head.end() || tail.find(x) != head.end())
            {
                continue;
            }
            else if (head.find(x - 1) != head.end() && tail.find(x + 1) != tail.end())
                //merge two union
            {
                auto n = make_shared<X>();
                n->head = tail[x + 1]->head;
                n->tail = head[x - 1]->tail;
                head.erase(x - 1);
                tail.erase(x + 1);
                head[n->head] = n;
                tail[n->tail] = n;
            }
            else if (head.find(x - 1) != head.end())
            {
                //add to the union that x - 1 is in
                auto n = head[x - 1];
                n->head = x;
                head.erase(x - 1);
                head[n->head] = n;
            }
            else if (tail.find(x + 1) != tail.end())
            {
                //add to the union that x + 1 is in
                auto n = tail[x + 1];
                n->tail = x;
                tail.erase(x + 1);
                tail[n->tail] = n;
            }
            else
            {
                //create single union
                auto n = make_shared<X>();
                n->head = x;
                n->tail = x;
                head[n->head] = n;
                tail[n->tail] = n;
            }
        }
        int max = 0;
        for (auto& kv : head)
        {
            max = std::max(max, kv.second->head - kv.second->tail + 1);
        }
        return max;
    }


};