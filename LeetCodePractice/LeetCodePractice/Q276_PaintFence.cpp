#include<vector>
using namespace std;

//read the answer
class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }
        vector<int> memo(n + 1, -1);
        return nw(n, k, memo);
    }

    int nw(int n, int k, vector<int>& memo) {
        if (n == 1) {
            return k;
        }
        if (n == 2) {
            return k * k;
        }
        if (memo[n] != -1) {
            return memo[n];
        }
        return memo[n] = (k - 1) * nw(n - 1, k, memo) + (k - 1) * nw(n - 2, k, memo);
    }
};


//4:33 5:25 TLE

class Solution {
public:
    int numWays(int n, int k) {
        if (n == 0 || k == 0) {
            return 0;
        }
        vector<vector<vector<int>>> memo(n + 1, vector<vector<int>>(k + 1, vector<int>(3, -1)));
        return nw(n, k, 0, k, memo);
    }

    int nw(int n, int color, int count, int k, vector<vector<vector<int>>>& memo) {
        if (n == 0) {
            return 1;
        }
        if (memo[n][color][count] != -1) {
            return memo[n][color][count];
        }
        int sum = 0;
        for (int i = 0; i < k; i++) {
            if (i == color) {
                if (count < 1) {
                    sum += nw(n - 1, i, 1, k, memo);
                }
                continue;
            }
            sum += nw(n - 1, i, 0, k, memo);

        }
        return memo[n][color][count] = sum;
    }
};