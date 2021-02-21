#include<vector>
#include<string>
using namespace std;
/*
Runtime: 32 ms, faster than 10.95% of C++ online submissions for Decode Ways II.
Memory Usage: 30.8 MB, less than 5.27% of C++ online submissions for Decode Ways II.
*/
//10:24 11:03, 40 mins hard
class Solution {
public:
    string s;
    int base = 1000000007;
    vector<long> memo;
    int numDecodings(string s) {
        this->s = s;
        memo = vector<long>(s.size() + 1, -1);
        return dp(0);
    }

    long dp(int i) {
        if (s[i] != '*' && s[i] == '0') {
            return 0;
        }
        if (i == s.size() - 1) {
            if (s[i] == '0') {
                return 0;
            }
            return s[i] == '*' ? 9 : 1;
        }
        if (i >= s.size()) {
            return 1;
        }
        if (memo[i] != -1) {
            return memo[i];
        }
        long result = 0;
        if (s[i] == '*') {
            result += (9 * dp(i + 1)) % base;
            if (s[i + 1] == '*') {
                result += (15 * dp(i + 2)) % base;
            }
            else {
                if (s[i + 1] < '7') {
                    result += (2 * dp(i + 2)) % base;
                }
                else {
                    result += dp(i + 2);
                }
            }
        }
        else if (s[i] == '2') {
            if (s[i + 1] == '*') {
                result += (6 * dp(i + 2)) % base;
            }
            else if (s[i + 1] < '7') {
                result += dp(i + 2);
            }
            result %= base;
            result += dp(i + 1);
        }
        else if (s[i] == '1') {
            if (s[i + 1] == '*') {
                result += (9 * dp(i + 2)) % base;
            }
            else {
                result += dp(i + 2);
            }
            result += dp(i + 1);
        }
        else {
            result += dp(i + 1);
        }
        return memo[i] = result % base;
    }
};