#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<utility>
using namespace std;

/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Word Break II.
Memory Usage: 7.9 MB, less than 100.00% of C++ online submissions for Word Break II.
*/


class Solution {//2:41
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<vector<int>> r;
        unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());
        vector<int> pos;
        dp(s, dict, 0, 0, pos, r);
        vector<string> result;
        for (auto& x : r) {
            string tmp;
            int idx = 0;
            for (auto& y : x) {
                tmp += s.substr(idx, y - idx + 1);
                tmp += " ";
                idx = y + 1;
            }
            tmp.pop_back();
            result.push_back(tmp);
        }
        return result;
    }

    void dp(string& s, unordered_set<string>& wordDict, int idx, int prev, vector<int>& position, vector<vector<int>>& result) {
        if (idx >= s.size()) {
            return;
        }
        if (idx == s.size() - 1) {
            if (wordDict.count(s.substr(prev, idx - prev + 1)) > 0) {
                position.push_back(idx);
                result.push_back(position);
                position.pop_back();
                return;
            }
        }
        if (wordDict.count(s.substr(prev, idx - prev + 1)) > 0) {
            position.push_back(idx);
            dp(s, wordDict, idx + 1, idx + 1, position, result);
            position.pop_back();
        }
        dp(s, wordDict, idx + 1, prev, position, result);
        return;
    }
};









//2/18 TLE
class Solution {
public:
    unordered_set<string> set;
    vector<vector<string>> memo;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        set = unordered_set<string>(wordDict.cbegin(), wordDict.cend());
        memo = vector<vector<string>>(s.size() + 1, vector<string>());
        dp(s, 0);
        return memo[0];
    }

    void dp(string& s, int pos) {
        if (pos == s.size()) {
            return;
        }
        if (memo[pos].size() > 0) {
            return;
        }
        string&& t = s.substr(pos, s.size() - pos);
        if (set.count(t) > 0) {
            memo[pos].push_back(t);
        }
        for (int i = 1; i < s.size() - pos; i++) {
            string tmp = s.substr(pos, i);
            if (set.count(tmp) > 0) {
                dp(s, pos + i);
                for (auto& x : memo[pos + i]) {
                    memo[pos].push_back(tmp + " " + x);
                }
            }
        }
        return;
    }

};





//7:42 8:08, n^2 but TLE

//9:18 new linked break point
/*
Runtime: 8 ms, faster than 94.50% of C++ online submissions for Word Break II.
Memory Usage: 14.3 MB, less than 24.89% of C++ online submissions for Word Break II.
*/

class Solution2 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0)
        {
            return vector<string>();
        }
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<vector<pair<int, int>>> memo(s.size() + 1,
            vector<pair<int, int>>());
        memo[0].push_back(pair<int, int>(0, 0));
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j <= s.size(); j++)
            {
                const auto t = s.substr(i, j - i);
                if (set.find(t) != set.cend() && memo[i].size() > 0)
                {
                    memo[j].push_back(pair<int, int>(i, j));
                }
            }
        }
        vector<string> result;
        for (auto& x : memo[s.size()])
        {
            for (auto& pp : memo[x.first])
            {
                b(pp, memo, result, s, s.substr(x.first, x.second - x.first));
            }
        }
        return result;
    }

    void b(pair<int, int>& p, vector<vector<pair<int, int>>>& memo, vector<string>& result, string& s, string&& ss)
    {
        if (p.first == 0 && p.second == 0)
        {
            result.push_back(ss);
            return;
        }
        for (auto& pp : memo[p.first])
        {
            b(pp, memo, result, s, s.substr(p.first, p.second - p.first) + " " + ss);
        }
    }
};


class Solution1 {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        if (s.size() == 0 || wordDict.size() == 0)
        {
            return vector<string>();
        }
        unordered_set<string> set(wordDict.begin(), wordDict.end());
        vector<vector<string>> memo(s.size() + 1,
            vector<string>());
        memo[0].push_back("");
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = i + 1; j <= s.size(); j++)
            {
                const auto t = s.substr(i, j - i);
                if (set.find(t) != set.cend())
                {
                    for (auto& x : memo[i])
                    {
                        memo[j].push_back(x + t + " ");
                    }
                }
            }
        }
        auto& result = memo[s.size()];
        std::for_each(result.begin(), result.end(), [](string& s) {s.pop_back(); });
        return result;
    }
};
