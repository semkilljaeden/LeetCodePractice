#include "LCHeader.h"
#include <queue>

class Solution {//3:30
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        unordered_map<int, unordered_set<int>> map;
        for (auto& x : pairs) {
            map[x[0]].insert(x[1]);
            map[x[1]].insert(x[0]);
        }
        unordered_set<int> head;
        using PQ = priority_queue<char, vector<char>, std::greater<char>>;
        vector<PQ> pq_list;
        pq_list.reserve(s.size());//VERY FUCKING IMPORTANT!!!!!! OTHERWISE THE VECTOR GOT EXPANDED AND THE PREVIOUS MEMORY LOCATION INVALID!!!!!!!!
        for (int i = 0; i < s.size(); i++) {
            head.insert(i);
        }
        unordered_map<int, PQ*> pq_map;
        unordered_set<int> visited;
        while (head.size() > 0) {
            pq_list.push_back(PQ());
            auto& x = pq_list.back();
            visited.clear();
            dfs(s, map, *head.cbegin(), head, visited, x);
            for (auto& v : visited) {
                pq_map[v] = &pq_list.back();
            }
        }
        string result = s;
        for (int i = 0; i < result.size(); i++) {
            if (pq_map.count(i) > 0) {
                auto& x = pq_map[i];
                result[i] = x->top();
                x->pop();
            }
        }
        return result;
    }

    void dfs(string& s, unordered_map<int, unordered_set<int>>& map, int head, unordered_set<int>& head_list, unordered_set<int>& visited, priority_queue<char, vector<char>, std::greater<char>>& pq) {
        if (visited.count(head) > 0) {
            return;
        }
        head_list.erase(head);
        visited.insert(head);
        pq.push(s[head]);
        for (auto& x : map[head]) {
            dfs(s, map, x, head_list, visited, pq);
        }

    }
};