#include<vector>
using namespace std;
//7:17 memo hahhahahhah 20mins one hard question. hahhahahhah why so easy
/*
Runtime: 184 ms, faster than 90.70% of C++ online submissions for Maximum Vacation Days.
Memory Usage: 23.7 MB, less than 68.60% of C++ online submissions for Maximum Vacation Days.
*/
class Solution {
public:
    int city;
    int week;
    vector<vector<int>> memo;
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        city = flights.size();
        week = days[0].size();
        memo = vector<vector<int>>(city + 1, vector<int>(week + 1, -1));
        int result = dp(flights, days, 0, 0);
        for (int i = 0; i < city; i++) {
            if (flights[0][i] == 1) {
                result = std::max(result, dp(flights, days, i, 0));
            }
        }
        return result;
    }

    int dp(vector<vector<int>>& f, vector<vector<int>>& d, int c, int w) {
        if (w >= week) {
            return 0;
        }
        if (memo[c][w] != -1) {
            return memo[c][w];
        }
        int result = dp(f, d, c, w + 1);
        for (int i = 0; i < city; i++) {
            if (f[c][i] == 1) {
                result = std::max(result, dp(f, d, i, w + 1));
            }
        }
        return memo[c][w] = result + d[c][w];
    }
};



//6:58 7:15 recursion

class Solution2 {
public:
    int city;
    int week;
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        city = flights.size();
        week = days[0].size();
        int result = dp(flights, days, 0, 0);
        for (int i = 0; i < city; i++) {
            if (flights[0][i] == 1) {
                result = std::max(result, dp(flights, days, i, 0));
            }
        }
        return result;
    }

    int dp(vector<vector<int>>& f, vector<vector<int>>& d, int c, int w) {
        if (w >= week) {
            return 0;
        }
        int result = dp(f, d, c, w + 1);
        for (int i = 0; i < city; i++) {
            if (f[c][i] == 1) {
                result = std::max(result, dp(f, d, i, w + 1));
            }
        }
        return result + d[c][w];
    }
};