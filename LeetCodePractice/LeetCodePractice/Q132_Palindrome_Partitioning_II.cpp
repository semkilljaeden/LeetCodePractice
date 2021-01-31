#include<vector>
#include<string>
#include<memory>
#include<sstream>
#include<string>
using namespace std;
//05:23 to 05:35 frst attempt
/*
Runtime: 260 ms, faster than 27.56% of C++ online submissions for Palindrome Partitioning II.
Memory Usage: 19.5 MB, less than 29.97% of C++ online submissions for Palindrome Partitioning II.
*/
class Solution {
public:

    int minCut(string s) {
        vector<int> memo(s.size(), -1);
        vector<vector<int>> memo2(s.size(), vector<int>(s.size(), -1));
        return cut(0, s, memo, memo2);
    }


    int cut(int i, string& s, vector<int>& memo, vector<vector<int>>& memo2)
    {
        if (i == s.size() - 1)
        {
            return 0;
        }
        if (memo[i] > -1)
        {
            return memo[i];
        }
        if (isPalindrome(s, i, s.size() - 1, memo2))
        {
            return memo[i] = 0;
        }
        int min = INT_MAX;
        for (int j = i; j < s.size() - 1; j++)
        {
            if (isPalindrome(s, i, j, memo2))
            {
                min = std::min(min, 1 + cut(j + 1, s, memo, memo2));
            }
        }
        return memo[i] = min;
    }

    bool isPalindrome(string& s, int i, int j, vector<vector<int>>& memo2) {
        if (i >= j) return true;
        if (memo2[i][j] > -1) return memo2[i][j];
        if (s[i] == s[j]) return memo2[i][j] = isPalindrome(s, i + 1, j - 1, memo2);
        return memo2[i][j] = false;
    }
};