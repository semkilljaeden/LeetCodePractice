#include "LCHeader.h"
#include <queue>

class Solution {//10:06 10:35
public:
    string removeKdigits(string num, int k) {
        k = num.size() - k;
        vector<int> stack;
        stack.reserve(k + 1);
        stack.push_back(INT_MAX);
        for (int i = 0; i < num.size(); i++) {
            while (stack.size() > 0 && num.size() - i + stack.size() > k && num[i] < stack.back()) {
                stack.pop_back();
            }
            stack.push_back(num[i]);
        }
        string result;
        bool leadZero = true;
        for (int i = 0; i < k; i++) {
            auto& x = stack[i];
            if (x == '0' && leadZero) {
                continue;
            }
            leadZero = false;
            result += x;
        }
        if (result == "") {
            result = "0";
        }
        return result;
    }
};



class Solution {//10:06 10:35
public:
    string removeKdigits(string num, int k) {
        auto cmp = [](pair<char, int>& a, pair<char, int>& b) {
            if (a.first != b.first) {
                return a.first > b.first;
            }
            return a.second > b.second;
        };
        priority_queue<pair<char, int>, vector<pair<char, int>>, decltype(cmp)> pq(cmp);
        string result;
        k = num.size() - k;
        int cur_pos = 0;
        bool leadingZero = true;
        for (int i = 0; i < num.size(); i++) {
            pq.push(make_pair(num[i], i));
            if (num.size() - i == k) {
                while (pq.top().second < cur_pos) {
                    pq.pop();
                }
                auto tmp = pq.top();
                if (tmp.first == '0' && leadingZero) {

                }
                else {
                    result += tmp.first;
                    leadingZero = false;
                }
                cur_pos = tmp.second;
                pq.pop();
                k--;
            }
        }
        if (result == "") {
            result = "0";
        }
        return result;
    }
};