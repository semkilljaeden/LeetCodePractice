#include<vector>
#include<string>
using namespace std;
//10mins, but not one shot AC
/*

Runtime: 4 ms, faster than 95.63% of C++ online submissions for Valid Palindrome.
Memory Usage: 7.7 MB, less than 28.85% of C++ online submissions for Valid Palindrome.
*/
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0;
        int r = s.size() - 1;
        while (l <= r)
        {
            char ll = tolower(s[l]);
            char rr = tolower(s[r]);
            if ((ll < 'a' || ll > 'z') && (ll < '0' || ll > '9')
                || (rr < 'a' || rr > 'z') && (rr < '0' || rr > '9'))
            {
                if ((ll < 'a' || ll > 'z') && (ll < '0' || ll > '9'))
                {
                    l++;
                }
                if ((rr < 'a' || rr > 'z') && (rr < '0' || rr > '9'))
                {
                    r--;
                }
                continue;
            }
            if (ll != rr)
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};