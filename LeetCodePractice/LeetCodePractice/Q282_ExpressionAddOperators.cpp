#include "LCHeader.h"


class Solution {//5:00
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.size() == 0) {
            return result;
        }
        if (num.size() == 1) {
            if (num[0] - '0' == target) {
                return vector<string> {num};
            }
            return result;
        }
        vector<pair<int, char>> s;
        vector<vector<pair<int, char>>> r;
        long cur = 0;
        for (int i = 0; i < num.size(); i++) {
            cur *= 10;
            cur += num[i] - '0';
            rec(num, target, i + 1, cur, 0, s, r);
            if (num[0] == '0') {
                break;
            }
        }
        result.reserve(r.size());
        for (auto& x : r) {
            string s;
            int j = 0;
            for (int i = 0; i < num.size(); i++) {
                if (j < x.size() && x[j].first == i) {
                    s += x[j].second;
                    j++;
                }
                s += num[i];
            }
            result.push_back(s);
        }
        return result;
    }

    void rec(string& num, int& target, int idx, long long tmp, long long sum, vector<pair<int, char>>& s, vector<vector<pair<int, char>>>& result) {
        if (idx == num.size()) {
            if (target == tmp + sum) {
                result.push_back(s);
            }
            return;
        }
        long cur = 0;
        for (int i = idx; i < num.size(); i++) {
            cur *= 10;
            cur += num[i] - '0';
            s.push_back(make_pair(idx, '*'));
            rec(num, target, i + 1, tmp * cur, sum, s, result);
            s.pop_back();
            s.push_back(make_pair(idx, '+'));
            rec(num, target, i + 1, cur, sum + tmp, s, result);
            s.pop_back();
            s.push_back(make_pair(idx, '-'));
            rec(num, target, i + 1, -cur, sum + tmp, s, result);
            s.pop_back();
            if (num[idx] == '0') {
                break;
            }
        }
    }
};



//5:58
/*
Runtime: 28 ms, faster than 95.61% of C++ online submissions for Expression Add Operators.
Memory Usage: 15.2 MB, less than 87.93% of C++ online submissions for Expression Add Operators.
*/

class Solution {//5:00
public:
    vector<string> addOperators(string num, int target) {
        vector<string> result;
        if (num.size() == 0) {
            return result;
        }
        if (num.size() == 1) {
            if (num[0] - '0' == target) {
                return vector<string> {num};
            }
            return result;
        }
        vector<pair<int, char>> s;
        vector<vector<pair<int, char>>> r;
        if (num[0] == '0') {
            rec(num, target, 1, 0, 0, s, r);
        }
        else {
            long cur = 0;
            for (int i = 0; i < num.size(); i++) {
                cur *= 10;
                cur += num[i] - '0';
                rec(num, target, i + 1, cur, 0, s, r);
            }
        }
        result.reserve(r.size());
        for (auto& x : r) {
            string s;
            int j = 0;
            for (int i = 0; i < num.size(); i++) {
                if (j < x.size() && x[j].first == i) {
                    s += x[j].second;
                    j++;
                }
                s += num[i];
            }
            result.push_back(s);
        }
        return result;
    }

    void rec(string& num, int& target, int idx, long long tmp, long long sum, vector<pair<int, char>>& s, vector<vector<pair<int, char>>>& result) {
        if (idx == num.size()) {
            if (target == tmp + sum) {
                result.push_back(s);
            }
            return;
        }
        long long cur = 0;
        if (num[idx] == '0') {
            s.push_back(make_pair(idx, '*'));
            rec(num, target, idx + 1, tmp * cur, sum, s, result);
            s.pop_back();
            s.push_back(make_pair(idx, '+'));
            rec(num, target, idx + 1, cur, sum + tmp, s, result);
            s.pop_back();
            s.push_back(make_pair(idx, '-'));
            rec(num, target, idx + 1, -cur, sum + tmp, s, result);
            s.pop_back();
            return;
        }
        for (int i = idx; i < num.size(); i++) {
            cur *= 10;
            cur += num[i] - '0';
            if (abs(cur * tmp) < INT_MAX) {
                s.push_back(make_pair(idx, '*'));
                rec(num, target, i + 1, tmp * cur, sum, s, result);
                s.pop_back();
            }
            s.push_back(make_pair(idx, '+'));
            rec(num, target, i + 1, cur, sum + tmp, s, result);
            s.pop_back();
            s.push_back(make_pair(idx, '-'));
            rec(num, target, i + 1, -cur, sum + tmp, s, result);
            s.pop_back();
        }
    }
};