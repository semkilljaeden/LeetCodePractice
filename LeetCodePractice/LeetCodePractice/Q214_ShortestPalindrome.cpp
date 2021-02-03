#include<vector>
#include<string>
using namespace std;
//11:40 12:38, TLE

class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.size() == 0)
        {
            return string();
        }
        int max = 1;
        for (int i = 1; i <= s.size() / 2; i++)
        {
            int tmp = match(s, i - 1, i + 1) * 2;
            if (tmp > 0)
            {
                tmp++;
            }
            max = std::max(max, tmp);
            if (s[i] == s[i + 1])
            {
                tmp = match(s, i - 1, i + 2) * 2;
                if (tmp > 0)
                {
                    tmp += 2;
                }
                max = std::max(max, tmp);
            }
        }
        if (s.size() > 1 && s[0] == s[1])
        {
            max = std::max(max, 2);
        }
        if (max == s.size())
        {
            return s;
        }
        string&& x = s.substr(max, s.size() - max);
        reverse(x.begin(), x.end());
        return x + s;
    }


    int match(string& s, int left, int right)
    {
        if (left < 0 || right >= s.size())
        {
            return 0;
        }
        if (left == 0)
        {
            if (s[left] == s[right])
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        if (s[left] != s[right])
        {
            return 0;
        }
        int r = match(s, left - 1, right + 1);
        if (r > 0)
        {
            return r + 1;
        }
        return 0;
    }
};