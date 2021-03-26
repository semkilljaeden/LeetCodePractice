#include<vector>
#include<string>
using namespace std;
//12:01

class Solution {
public:
    int numDecodings(string s) {
        vector<vector<int>> memo(s.size() + 1, vector<int>(3, -1));
        return dp(s, 0, 0, memo);
    }

    int dp(string& s, int idx, int lead, vector<vector<int>>& memo) {
        if (memo[idx][lead] != -1) {
            return memo[idx][lead];
        }
        if (idx == s.size()) {
            return memo[idx][lead] = lead == 0 ? 1 : 0;
        }
        int count = 0;
        if (lead == 1) {
            count += dp(s, idx + 1, 0, memo);
        }
        else if (lead == 2) {
            if (s[idx] >= '0' && s[idx] <= '6') {
                count += dp(s, idx + 1, 0, memo);
            }
            else {
                return memo[idx][lead] = 0;
            }
        }
        else {
            if (s[idx] == '0') {
                return 0;
            }
            count += dp(s, idx + 1, 0, memo);
            if (s[idx] == '1') {
                count += dp(s, idx + 1, 1, memo);
            }
            if (s[idx] == '2') {
                count += dp(s, idx + 1, 2, memo);
            }
        }
        return memo[idx][lead] = count;
    }
};