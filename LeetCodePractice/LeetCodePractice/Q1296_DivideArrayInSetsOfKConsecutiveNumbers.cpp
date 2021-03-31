#include "LCHeader.h"
#include <queue>
//10mins

class Solution {//12:26
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        for (auto& x : nums) {
            map[x]++;
        }
        vector<int> index;
        index.reserve(map.size());
        for (auto& x : map) {
            index.push_back(x.first);
        }
        sort(index.begin(), index.end());
        for (int i = 0; i < index.size(); i++) {
            int& cur = index[i];
            while (map.count(cur) > 0) {
                for (int i = 0; i < k; i++) {
                    if (map.count(cur + i) == 0) {
                        return false;
                    }
                    map[cur + i]--;
                    if (map[cur + i] == 0) {
                        map.erase(cur + i);
                    }
                }
            }
        }
        return true;
    }
};







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