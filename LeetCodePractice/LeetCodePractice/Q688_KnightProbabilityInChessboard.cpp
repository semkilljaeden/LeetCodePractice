#include<vector>
using namespace std;
//11:13 11:45 12:00, misread the question, a bit slow but of a reason
/*
Runtime: 8 ms, faster than 83.84% of C++ online submissions for Knight Probability in Chessboard.
Memory Usage: 8.9 MB, less than 30.95% of C++ online submissions for Knight Probability in Chessboard.
*/
class Solution {
public:
    int N;
    int K;
    double base;
    double knightProbability(int N, int K, int r, int c) {
        vector<vector<vector<double>>> onb(N + 5, vector<vector<double>>(N + 5, vector<double>(K + 1, -1)));
        this->N = N;
        this->K = K;
        base = pow(8, K);
        dp(r + 2, c + 2, K, onb);
        return (double)onb[r + 2][c + 2][K];
    }

    double dp(int r, int c, int K, vector<vector<vector<double>>>& onb) {
        if (K == 0) {
            if (r < 2 || r >= N + 2 || c < 2 || c >= N + 2) {
                onb[r][c][K] = 0;
            }
            else {
                onb[r][c][K] = 1 / base;
            }
            return 0;
        }
        if (r < 2 || r >= N + 2 || c < 2 || c >= N + 2) {
            onb[r][c][K] = 0;
            return 0;
        }
        if (onb[r][c][K] != -1) {
            return 0;
        }
        double onbb = 0;
        double offbb = 0;
        dp(r + 2, c + 1, K - 1, onb);
        onbb += onb[r + 2][c + 1][K - 1];

        dp(r + 2, c - 1, K - 1, onb);
        onbb += onb[r + 2][c - 1][K - 1];
        

        dp(r - 2, c + 1, K - 1, onb);
        onbb += onb[r - 2][c + 1][K - 1];
        

        dp(r - 2, c - 1, K - 1, onb);
        onbb += onb[r - 2][c - 1][K - 1];
        

        dp(r + 1, c + 2, K - 1, onb);
        onbb += onb[r + 1][c + 2][K - 1];
        

        dp(r - 1, c + 2, K - 1, onb);
        onbb += onb[r - 1][c + 2][K - 1];
        

        dp(r + 1, c - 2, K - 1, onb);
        onbb += onb[r + 1][c - 2][K - 1];
        

        dp(r - 1, c - 2, K - 1, onb);
        onbb += onb[r - 1][c - 2][K - 1];
        onb[r][c][K] = onbb;
        

        return 0;
    }
};