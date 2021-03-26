#include "LCHeader.h"
#include<queue>

class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, vector<char>> map;
        unordered_map<char, int> in_map;
        for (auto& w : words) {
            for (auto& c : w) {
                in_map[c] = 0;
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            auto& left = words[i];
            auto& right = words[i + 1];
            int j = 0;
            while (left[j] == right[j] && j < left.size() && j < right.size()) {
                j++;
            }
            if (j < right.size() && j < left.size()) {
                map[left[j]].push_back(right[j]);
                in_map[right[j]]++;
            }
            else if (left.size() > right.size()) {
                return "";
            }
        }
        string result;
        queue<char> q;
        for (auto& x : in_map) {
            if (x.second == 0) {
                q.push(x.first);
            }
        }
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto x = q.front();
                q.pop();
                result += x;
                for (auto& y : map[x]) {
                    in_map[y]--;
                    if (in_map[y] == 0) {
                        q.push(y);
                    }
                }
            }
        }
        if (result.size() != in_map.size()) {
            return "";
        }
        return result;
    }
};


class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, char> graph;
        unordered_set<char> head;
        int flag = false;
        for (auto& x : words) {
            if (x.size() == 1) {
                flag = true;
            }
            for (auto& c : x) {
                head.insert(c);
            }
        }
        for (int i = 0; i < words.size() - 1; i++) {
            auto& prev = words[i];
            auto& x = words[i + 1];
            for (int i = 0; i < x.size(); i++) {
                if (i >= prev.size() || i < prev.size() && x[i] == prev[i]) {
                }
                else {
                    auto tmp = prev[i];
                    int count = 0;
                    while (graph.count(tmp) > 0) {
                        count++;
                        if (count >= 26) {
                            return "";
                        }
                        tmp = graph[tmp];
                    }
                    if (head.count(x[i]) > 0 && tmp != '0') {
                        head.erase(x[i]);
                    }
                    if (tmp != x[i]) {
                        graph[tmp] = x[i];
                    }
                    flag = true;
                    break;
                }
            }
        }
        if (graph.size() == 0 && !flag) {
            return "";
        }
        string result;
        unordered_set<char> set;
        queue<char> q;
        for (auto& x : head) {
            q.push(x);
        }
        while (q.size() > 0) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                result += q.front();
                q.pop();
                auto& c = result.back();
                if (graph.count(c) > 0 && set.count(graph[c]) == 0) {
                    set.insert(graph[c]);
                    q.push(graph[c]);
                }
            }
        }
        return result;
    }
};