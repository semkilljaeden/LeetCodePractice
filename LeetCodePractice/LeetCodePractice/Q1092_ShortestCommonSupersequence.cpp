#include "LCHeader.h"
//11:28 AC nearly one hour

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<int>> memo2(str1.size() + 1, vector<int>(str2.size() + 1, -1));
        vector<vector<vector<int>>> memo(str1.size() + 1, vector<vector<int>>(str2.size() + 1, vector<int>(2, -1)));
        dp(str1, str2, 0, 0, memo, memo2);
        auto prev = vector<int>{ 0, 0 };
        string result;
        while (prev[0] < str1.size() && prev[1] < str2.size()) {
            auto& next = memo[prev[0]][prev[1]];
            if (next[0] > prev[0]) {
                result += str1[prev[0]];
            }
            else {
                result += str2[prev[1]];
            }
            prev = next;
        }
        if (prev[0] == str1.size()) {
            result += str2.substr(prev[1], str2.size() - prev[1]);
        }
        else {
            result += str1.substr(prev[0], str1.size() - prev[0]);
        }
        return result;
    }

    int dp(string& s1, string& s2, int i, int j, vector<vector<vector<int>>>& memo, vector<vector<int>>& memo2) {
        if (memo2[i][j] != -1) {
            return memo2[i][j];
        }
        if (i == s1.size()) {
            memo[i][j][0] = i;
            memo[i][j][1] = j;
            return memo2[i][j] = s2.size() - j;
        }
        else if (j == s2.size()) {
            memo[i][j][0] = i;
            memo[i][j][1] = j;
            return memo2[i][j] = s1.size() - i;
        }
        int a1 = INT_MAX;
        int a2 = 1 + dp(s1, s2, i + 1, j, memo, memo2);
        int a3 = 1 + dp(s1, s2, i, j + 1, memo, memo2);
        if (s1[i] == s2[j]) {
            a1 = 1 + dp(s1, s2, i + 1, j + 1, memo, memo2);
        }
        if (i == 0 && j == 0) {
            int z = 0;
        }
        if (a1 <= a2 && a1 <= a3) {
            memo[i][j][0] = i + 1;
            memo[i][j][1] = j + 1;
            return memo2[i][j] = a1;
        }
        else if (a2 <= a1 && a2 <= a3) {
            memo[i][j][0] = i + 1;
            memo[i][j][1] = j;
            return memo2[i][j] = a2;
        }
        else { //if(a3 <= a1 && a3 <= a2)
            memo[i][j][0] = i;
            memo[i][j][1] = j + 1;
            return memo2[i][j] = a3;
        }
    }
};

//10:33 11:01 TLE
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        vector<vector<string>> memo(str1.size() + 1, vector<string>(str2.size() + 1, ""));
        dp(str1, str2, 0, 0, memo);
        return memo[0][0];
    }

    int dp(string& s1, string& s2, int i, int j, vector<vector<string>>& memo) {
        if (i == s1.size()) {
            memo[i][j] = s2.substr(j, s2.size() - j);
            return memo[i][j].size();
        }
        else if (j == s2.size()) {
            memo[i][j] = s1.substr(i, s1.size() - i);
            return memo[i][j].size();
        }
        int a1 = INT_MAX;
        int a2 = dp(s1, s2, i + 1, j, memo);
        int a3 = dp(s1, s2, i, j + 1, memo);
        if (s1[i] == s2[j]) {
            a1 = dp(s1, s2, i + 1, j + 1, memo);
        }
        if (a1 <= a2 && a1 <= a3) {
            memo[i][j] = s1[i] + memo[i + 1][j + 1];
        }
        else if (a2 <= a1 && a2 <= a3) {
            memo[i][j] = s1[i] + memo[i + 1][j];
        }
        else if (a3 <= a1 && a3 <= a2) {
            memo[i][j] = s2[j] + memo[i][j + 1];
        }
        return memo[i][j].size();
    }
};