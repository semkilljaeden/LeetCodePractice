#include "LCHeader.h"
//10:30 10:54, the idea is so clear, some case was not clear

class Solution {
public:
    string countOfAtoms(string formula) {
        int idx = 0;
        auto m = rec(formula, idx);
        vector<pair<string, int>> r(m.cbegin(), m.cend());
        sort(r.begin(), r.end(), [](const pair<string, int>& left, const pair<string, int>& right) {
            return left.first < right.first;
        });
        string result;
        for (auto& x : r) {
            result += x.first;
            if (x.second > 1) {
                result += to_string(x.second);
            }
        }
        return result;
    }

    unordered_map<string, int> rec(string& s, int& i) {
        vector<unordered_map<string, int>> stack;
        for (; i < s.size(); i++) {
            if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
                string name = string(1, s[i]);
                i++;
                while (i < s.size() && s[i] >= 'a' && s[i] <= 'z') {
                    name += s[i];
                    i++;
                }
                i--;
                stack.push_back({ {name, 1} });
            }
            else if (isdigit(s[i])) {
                string name = string(1, s[i]);
                i++;
                while (i < s.size() && s[i] >= '0' && s[i] <= '9') {
                    name += s[i];
                    i++;
                }
                i--;
                for (auto& x : stack.back()) {
                    x.second *= stoi(name);
                }
            }
            else if (s[i] == '(') {
                i++;
                stack.push_back(rec(s, i));
            }
            else if (s[i] == ')') {
                break;
            }
        }
        auto& map = stack[0];
        for (int j = 1; j < stack.size(); j++) {
            for (auto& x : stack[j]) {
                map[x.first] += x.second;
            }
        }
        return map;

    }
};