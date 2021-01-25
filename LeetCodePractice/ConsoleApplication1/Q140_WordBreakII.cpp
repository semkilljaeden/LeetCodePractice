#include<vector>
#include<string>
#include<unordered_set>
#include<algorithm>
#include<utility>
using namespace std;

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
