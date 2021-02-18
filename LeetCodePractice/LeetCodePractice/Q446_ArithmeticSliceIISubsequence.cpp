#include<vector>
#include <iostream>
#include<unordered_map>
using namespace std;
//3:48 O(n^2), finally understand the answer
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& AA) {
        int n = AA.size();
        int result = 0;
        if (n < 3) {
            return 0;
        }
        vector<long> A(AA.cbegin(), AA.cend());
        vector<unordered_map<long, int>> memo(n + 1);
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; j--) {
                long del = A[i] - A[j];
                int r = 0;
                if (memo[j].find(del) != memo[j].end()) {
                    r += memo[j][del];
                }
                memo[i][del] += r + 1;
                result += r;
            }
        }
        return result;
    }


};

//3:42

//O(n^3) TLE

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& AA) {
        int n = AA.size();
        int result = 0;
        if (n < 3) {
            return 0;
        }
        vector<long> A(AA.cbegin(), AA.cend());
        vector<vector<unordered_map<long, int>>> memo(n + 1,
            vector<unordered_map<long, int>>(n + 1));
        for (int i = 1; i < n; ++i) {
            for (int j = i - 1; j >= 0; j--) {
                long del = A[i] - A[j];
                memo[i][2][del] += 1;
                for (int k = i; k >= 2; k--) {
                    int r = 0;
                    if (memo[j][k].find(del) != memo[j][k].end()) {
                        r += memo[j][k][del];
                    }
                    memo[i][k + 1][del] += r;
                    result += r;
                }

            }
        }
        return result;
    }


};

//8:50 9:42 2:27 fucking tedious recursive




class Solution {
public:
    int result = 0;
    long nan = (long)INT_MIN + (long)INT_MIN - 1;
    int numberOfArithmeticSlices(vector<int>& AA) {
        vector<long> A(AA.cbegin(), AA.cend());
        vector<long> trace;
        dp(A, 0, nan, nan, 0, true, trace);
        return result;
    }

    void dp(vector<long>& AA, int i, long diff, int prev, int count, bool ok, vector<long>& trace) {
        if (i >= AA.size()) {
            return;
        }
        trace.push_back(AA[i]);
        bool c = (AA[i] - prev) == diff;
        if (ok && count >= 2 && c) {
            result += 1;
        }
        if (count < 2) {
            dp(AA, i + 1, AA[i] - prev, AA[i], count + 1, true, trace);
        }
        else if (count == 2) {
            dp(AA, i + 1, AA[i] - prev, AA[i], count + 1, c, trace);
        }
        else {
            dp(AA, i + 1, AA[i] - prev, AA[i], count + 1, ok && c, trace);
        }
        trace.pop_back();
        if (count < 3) {
            dp(AA, i + 1, diff, prev, count, true, trace);
        }
        else {
            dp(AA, i + 1, diff, prev, count, ok, trace);
        }

    }
};