#include "LCHeader.h"
class Solution {
public:
    double soupServings(int N) {
        if (N > 5000) {
            return 1;
        }
        vector<vector<double>> memo(N + 1, vector<double>(N + 1, -1));
        N = (N + 24) / 25;
        auto r = dp(N, N, memo);
        return r;
    }

    double dp(int An, int Bn, vector<vector<double>>& memo) {
        if (An <= 0 && Bn <= 0) {
            return 0.5;
        }
        if (An <= 0 && Bn > 0) {
            return 1;
        }
        if (An > 0 && Bn <= 0) {
            return 0;
        }
        if (memo[An][Bn] + 1 > 0.0000001) {
            return memo[An][Bn];
        }
        double result = 0;
        result += 0.25 * dp(An - 4, Bn, memo);
        result += 0.25 * dp(An - 3, Bn - 1, memo);
        result += 0.25 * dp(An - 2, Bn - 2, memo);
        result += 0.25 * dp(An - 1, Bn - 3, memo);
        return memo[An][Bn] = result;
    }
};


//3:03 weird. no idea why this one does not work
class Solution {
public:
    double soupServings(double N) {
        auto r = dp(N, N);
        double sum = r[0] + r[1] + r[2];
        double result = r[1] / sum + r[0] / sum / 2.0;
        return result;
    }

    vector<double> dp(int An, int Bn) {
        if (An <= 0 && Bn <= 0) {
            return vector<double>{1, 0, 0};
        }
        if (An <= 0 && Bn > 0) {
            return vector<double>{0, 1, 0};
        }
        if (An > 0 && Bn <= 0) {
            return vector<double>{0, 0, 1};
        }
        vector<double> result(3, 0);
        plus(result, dp(An - 100, Bn));
        plus(result, dp(An - 75, Bn - 25));
        plus(result, dp(An - 50, Bn - 50));
        plus(result, dp(An - 25, Bn - 75));
        return result;
    }

    void plus(vector<double>& l, const vector<double>& r) {
        for (double i = 0; i < 3; i++) {
            l[i] += r[i];
        }
        return;
    }
};