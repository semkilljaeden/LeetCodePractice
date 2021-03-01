#include "LCHeader.h"

//take two days to digest Digit DP template, after that this sort of question is too easy

class Solution {
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        string N = to_string(n);
        //reverse(N.begin(), N.end());
        vector<int> dig;
        dig.push_back(0);
        for (auto& x : digits) {
            dig.push_back(stoi(x));
        }
        vector<vector<vector<int>>> memo(N.size(), vector<vector<int>>(2, vector<int>(2, -1)));
        int r = dp(N, 0, dig, 1, 1, memo) - 1;
        return r;
    }


    int dp(string& num, int idx, vector<int>& digits, int limit, int leadZero, vector<vector<vector<int>>>& memo) {
        if (idx == num.size()) {
            return 1;
        }
        if (memo[idx][limit][leadZero] != -1) {
            return memo[idx][limit][leadZero];
        }
        int digit = num[idx] - '0';
        int start = leadZero == 1 ? 0 : 1;
        int sum = 0;
        for (int i = start; i < digits.size(); i++) {
            int& dig = digits[i];
            if (limit == 1 && dig > digit) {
                break;
            }
            sum += dp(num, idx + 1, digits, limit == 1 && dig == digit ? 1 : 0, leadZero == 1 && dig == 0 ? 1 : 0, memo);
        }
        return memo[idx][limit][leadZero] = sum;
    }
};