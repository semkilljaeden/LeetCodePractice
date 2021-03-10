#include "LCHeader.h"
#include <queue>
#include <functional>
//8:47 9:03

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (auto& x : words) {
            map[x]++;
        }
        std::function<bool(const pair<string, int>&, const pair<string, int>&)> cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };
        priority_queue<pair<string, int>, vector<pair<string, int>>, std::function<bool(const pair<string, int>&, const pair<string, int>&)>> pq(cmp);
        for (auto& x : map) {
            pq.push(x);
            if (pq.size() > k) {
                pq.pop();
            }
        }
        vector<string> result;
        while (pq.size() > 0) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        reverse(result.begin(), result.end());
        return result;
    }
};