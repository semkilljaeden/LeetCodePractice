#include<vector>
#include<string>
using namespace std;
//2:44
class Solution {
public:
    string kthSmallestPath(vector<int>& d, int k) {
        vector<vector<int>> memo(d[0] + 2, vector<int>(d[1] + 2, 0));
        memo[d[0] + 1][d[1]] = 1;
        for (int i = d[0]; i >= 0; i--) {
            for (int j = d[1]; j >= 0; j--) {
                memo[i][j] = memo[i][j + 1] + memo[i + 1][j];
            }
        }
        int row = 0;
        int col = 0;
        string result;
        while (row != d[1] && col != d[0]) {
            if (k <= memo[col][row + 1]) {
                row++;
                result += 'H';
            }
            else {
                k -= memo[col][row + 1];
                result += 'V';
                col++;
            }
        }
        while (row < d[1]) {
            result += 'H';
            row++;
        }
        while (col < d[0]) {
            result += 'V';
            col++;
        }
        return result;
    }

};



//11:44 12:16 TLE

class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        return dp(destination, 0, 0, k, "");
    }

    string dp(vector<int>& d, int i, int j, int& k, string action) {
        string t = "";
        if (i == d[1] && j == d[0]) {
            k--;
            if (k == 0) {
                return action;
            }
            return "";
        }
        if (i > d[1] || j > d[0]) {
            return "";
        }
        t = dp(d, i + 1, j, k, "H");
        t = (t == "" ? t : action + t);
        if (t == "") {
            t = dp(d, i, j + 1, k, "V");
            t = (t == "" ? t : action + t);
        }
        return t;
    }
};