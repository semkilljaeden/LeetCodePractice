#include<vector>
#include<string>
using namespace std;
//12:00 : 12:29 medium, a bit slow, read the hint,shit

/**
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.
Memory Usage: 6.6 MB, less than 99.31% of C++ online submissions for Longest Substring with At Most Two Distinct Characters.

*/

class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        if (s.size() <= 2)
        {
            return s.size();
        }
        char a = s[0];
        char b = s[1];
        int left = 0;
        int right = 2;
        int pos = a == b ? 0 : 1;
        int max = 0;
        while (right < s.size())
        {
            if (s[right] != a && a == b)
            {
                pos = right;
                b = s[right];
            }
            else if (s[right] != b && s[right] == a)
            {
                pos = right;
                char c = a;
                a = b;
                b = c;
            }
            else if (s[right] != a && s[right] != b)
            {
                left = pos;
                pos = right;
                a = b;
                b = s[right];
            }
            right++;
            max = std::max(max, right - left);
        }
        return max;
    }
};