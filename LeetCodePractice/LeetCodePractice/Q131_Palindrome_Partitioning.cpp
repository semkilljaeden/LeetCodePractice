#include<vector>
#include<string>
#include<memory>
#include<sstream>
#include<set>
//03:08 to 05:17
/*
Runtime: 80 ms, faster than 91.50% of C++ online submissions for Palindrome Partitioning.
Memory Usage: 49.4 MB, less than 91.19% of C++ online submissions for Palindrome Partitioning.
*/
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<int>> memo(s.size(), vector<int>(s.size(), -1));
        vector<vector<string>> results;
        vector<string> result;
        dfs(0, s, results, result, memo);
        return results;
    }

    void dfs(int start, string& s, vector<vector<string>>& results, vector<string>& result, vector<vector<int>>& memo)
    {
        if (start >= s.size())
        {
            return;
        }
        if (memo[start][s.size() - 1] == 1 || memo[start][s.size() - 1] == -1
            && isPalindrome(s, start, s.size() - 1))
        {
            result.push_back(s.substr(start, s.size() - start));
            results.push_back(result);
            result.pop_back();
            memo[start][s.size() - 1] = 1;
        }
        if (start == s.size() - 1)
        {
            return;
        }
        for (int end = start; end < s.size(); end++)
        {
            if (memo[start][end] == 1 || memo[start][end] == -1
                && isPalindrome(s, start, end))
            {
                result.push_back(s.substr(start, end - start + 1));
                dfs(end + 1, s, results, result, memo);
                result.pop_back();
            }
        }
        return;
    }

    bool isPalindrome(string& s, int i, int j)
    {
        if (s.size() == 0)
        {
            return false;
        }
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};


class Solution2 {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<shared_ptr<set<vector<string>>>>> memo(s.size(), vector<shared_ptr<set<vector<string>>>>(s.size(), nullptr));
        auto r = rec(0, s.size() - 1, s, memo);
        vector<vector<string>> result;
        result.insert(result.end(), r->cbegin(), r->cend());
        return result;
    }

    shared_ptr<set<vector<string>>> rec(int i, int j, string& s, vector<vector<shared_ptr<set<vector<string>>>>>& memo)
    {
        if (i == j)
        {
            auto tttt = make_shared<set<vector<string>>>();
            tttt->insert(vector<string>{s.substr(i, 1)});
            return tttt;
        }
        if (memo[i][j] != nullptr)
        {
            return memo[i][j];
        }
        auto x = make_shared<set<vector<string>>>();
        if (isPalindrome(s, i, j))
        {
            x->insert(vector<string>{s.substr(i, j - i + 1)});
        }

        for (int k = i; k <= j - 1; k++)
        {
            auto a = rec(i, k, s, memo);
            auto b = rec(k + 1, j, s, memo);
            for (auto& t : *a)
            {
                for (auto& tt : *b)
                {
                    vector<string> tmp;
                    tmp.insert(tmp.end(), t.cbegin(), t.cend());
                    tmp.insert(tmp.end(), tt.cbegin(), tt.cend());
                    x->insert(tmp);
                }
            }
        }
        return memo[i][j] = x;

    }


    bool isPalindrome(string& s, int i, int j)
    {
        if (s.size() == 0)
        {
            return false;
        }
        while (i <= j)
        {
            if (s[i] != s[j])
            {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};