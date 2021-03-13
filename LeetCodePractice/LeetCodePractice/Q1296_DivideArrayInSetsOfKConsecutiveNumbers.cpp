#include "LCHeader.h"
#include <queue>
//4:58 5:13
/*
Runtime: 116 ms, faster than 97.66% of C++ online submissions for Divide Array in Sets of K Consecutive Numbers.
Memory Usage: 54.5 MB, less than 12.27% of C++ online submissions for Divide Array in Sets of K Consecutive Numbers.
*/
class Solution {
public:
    class Node {
    public:
        int number;
        int count;
        Node() {
            count = 0;
        }

    };
    bool isPossibleDivide(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        queue<Node*> q;
        unordered_map<int, Node> map;
        for (int i = 0; i < nums.size(); i++) {
            if (map.count(nums[i]) == 0) {
                map[nums[i]].number = nums[i];
                map[nums[i]].count++;
                q.push(&map[nums[i]]);
            }
            else {
                map[nums[i]].count++;
            }
        }

        while (q.size() > 0) {
            auto node = q.front();
            if (node->count == 0) {
                q.pop();
                continue;
            }
            int base = node->number;
            node->count--;
            for (int i = 1; i < k; i++) {
                if (map[base + i].count == 0) {
                    return false;
                }
                map[base + i].count--;
            }
        }
        return true;
    }
};