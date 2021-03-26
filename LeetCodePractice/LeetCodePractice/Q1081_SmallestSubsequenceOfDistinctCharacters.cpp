#include "LCHeader.h"
//5:13
/*

Runtime: 0 ms, faster than 100.00% of C++ online submissions for Remove Duplicate Letters.
Memory Usage: 6.6 MB, less than 57.81% of C++ online submissions for Remove Duplicate Letters.
*/
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(s.size(), 0);
        unordered_set<char> p;
        auto prev = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int tmp = 1 << (s[i] - 'a');
            v[i] = (prev | tmp);
            prev = v[i];
        }
        int full = v[0];

        int i = 0;
        string result;

        while (full > 0) {
            int idx = i;
            char c = 'z' + 1;
            for (int j = i; j < s.size(); j++) {
                if ((v[j] | full) > v[j]) {
                    break;
                }
                if ((full | (1 << (s[j] - 'a'))) != full) {
                    continue;
                }
                if (s[j] < c) {
                    c = s[j];
                    idx = j;
                }
            }
            result += c;
            full -= 1 << (c - 'a');
            i = idx + 1;
        }
        return result;

    }
};



//5:11 weird bug
// 
// 
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> v(s.size(), 0);
        unordered_set<char> p;
        auto prev = 0;
        for (int i = s.size() - 1; i >= 0; i--) {
            int tmp = 1 << (s[i] - 'a');
            v[i] = (prev | tmp);
            prev = v[i];
        }
        int full = v[0];

        int i = 0;
        string result;

        while (full > 0) {
            int idx = i;
            char c = 'z' + 1;
            for (int j = i; j < s.size(); j++) {
                if (v[j] < full) {
                    break;
                }
                if ((full | (1 << (s[j] - 'a'))) != full) {
                    continue;
                }
                if (s[j] < c) {
                    c = s[j];
                    idx = j;
                }
            }
            result += c;
            full -= 1 << (c - 'a');
            i = idx + 1;
        }
        return result;

    }
};
//4:06 4:38 stupid TLE

class Solution {
public:
    string removeDuplicateLetters(string s) {
        int mark = 0;
        for (auto& x : s) {
            mark |= (1 << (x - 'a'));
        }
        vector<vector<string>> memo(s.size(), vector<string>((1 << 26) - 1, "1"));
        string result = dp(s, 0, 0, mark, memo);
        reverse(result.begin(), result.end());
        return result;
    }

    string dp(string& s, int idx, int mask, int& mark, vector<vector<string>>& memo) {
        if (mask == mark) {
            return "";
        }
        if (idx == s.size()) {
            return "0";
        }
        if (memo[idx][mask] != "1") {
            return memo[idx][mask];
        }
        int tmp = (1 << (s[idx] - 'a'));
        if ((mark | tmp) > mark || (mask | tmp) == mask) {
            return dp(s, idx + 1, mask, mark, memo);
        }
        auto left = dp(s, idx + 1, mask | tmp, mark, memo);
        auto right = dp(s, idx + 1, mask, mark, memo);
        return memo[idx][mask] = compare(left, right, s[idx]);
    }

    string compare(string& left, string& right, char c) {
        if (left == "0") {
            return right;
        }
        else if (right == "0") {
            left += c;
            return left;
        }
        left += c;
        for (int i = left.size() - 1; i >= 0; i--) {
            if (left[i] < right[i]) {
                return left;
            }
            else if (left[i] > right[i]) {
                return right;
            }
        }
        return left;
    }
};