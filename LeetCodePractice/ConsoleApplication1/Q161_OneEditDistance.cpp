#include<vector>
#include<string>
using namespace std;
//14mins ,took a while to debug corner case
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for One Edit Distance.
Memory Usage: 6.5 MB, less than 79.23% of C++ online submissions for One Edit Distance.
*/
class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        if (abs((int)(s.size() - t.size())) > 1)
        {
            return false;
        }

        int i = 0;
        int j = 0;
        bool checked = false;
        while (i < s.size() && j < t.size())
        {
            if (s[i] != t[j])
            {
                if (checked)
                {
                    return false;
                }
                if (s.size() < t.size())
                {
                    j++;
                }
                else if (s.size() > t.size())
                {
                    i++;
                }
                else
                {
                    i++;
                    j++;
                }
                checked = true;
            }
            else
            {
                i++;
                j++;
            }
        }
        if ((s.size() == 0 || t.size() == 0 || !checked) && abs((int)(s.size() - t.size())) == 1)
        {
            return true;
        }
        return checked;
    }
};