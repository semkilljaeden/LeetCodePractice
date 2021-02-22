#include<vector>
#include<algorithm>
#include<string>
using namespace std;
//12:30 12:45 getting better!!!!!!! medium

class Solution {
public:
    int count = 0;
    vector<vector<int>> memo;
    int countSubstrings(string s) {
        memo = vector<vector<int>>(s.size() + 1, vector<int>(s.size() + 1, -1));
        dp(s, 0, s.size() - 1);
        return count;
    }
    int dp(string& s, int left, int right) {
        int length = 0;
        if (right < left) {
            return 0;
        }
        if (memo[left][right] != -1) {
            return memo[left][right];
        }
        if (left == right) {
            count++;
            return memo[left][right] = 1;
        }
        if (s[left] == s[right]) {
            int tmp = dp(s, left + 1, right - 1);
            int ll = right - 1 - left - 1 + 1;
            if (tmp == (ll < 0 ? 0 : ll)) {
                count++;
            }
            length = 2 + tmp;
        }
        length = std::max(length, dp(s, left, right - 1));
        length = std::max(length, dp(s, left + 1, right));
        return memo[left][right] = length;
    }
};