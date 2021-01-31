#include<vector>
#include<string>
//30mins, but 2d-vector recursion + memorization in c++ does not pass time limit, omfg, i need to use reference!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
using namespace std;
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<int>> memo(s.size(), vector<int>(t.size(), -1));
        return num(s, t, 0, 0, memo);
    }

    int num(string& s, string& t, int sp, int tp, vector<vector<int>>& memo)
    {
        if (tp == t.size())
        {
            return 1;
        }
        else if (sp == s.size())
        {
            return 0;
        }
        if (memo[sp][tp] > -1)
        {
            return memo[sp][tp];
        }
        int count = 0;
        if (s[sp] == t[tp])
        {
            count += num(s, t, sp + 1, tp + 1, memo);

        }
        count += num(s, t, sp + 1, tp, memo);
        return memo[sp][tp] = count;
    }
};
class Solution2 {
public:
    int numDistinct(string s, string t) {
        vector<vector<long>> memo(s.size() + 1, vector<long>(t.size() + 1, 0));
        for (int i = 0; i <= t.size(); i++)
        {
            memo[s.size()][i] = 0;
        }
        for (int i = 0; i <= s.size(); i++)
        {
            memo[i][t.size()] = 1;
        }
        for (int i = s.size() - 1; i >= 0; i--)
        {
            for (int j = t.size() - 1; j >= 0; j--)
            {
                memo[i][j] = memo[i + 1][j];
                if (s[i] == t[j])
                {
                    memo[i][j] += memo[i + 1][j + 1];
                }
            }
        }
        return memo[0][0];
    }
};

//Interesting fact: memorization can be faster than DP considering branch pruning, MM only runs 25477 cases whereas DP runs 46000 cases
