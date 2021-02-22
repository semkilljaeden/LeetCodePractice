#include<vector>
using namespace std;
//8:58 9:26 nice~ Hard question
/*
Runtime: 12 ms, faster than 83.53% of C++ online submissions for Coin Path.
Memory Usage: 13.3 MB, less than 36.47% of C++ online submissions for Coin Path.
*/
class Solution {
public:
    vector<int> A;
    int B;
    int max = 10000000000;
    vector<int> cheapestJump(vector<int>& A, int B) {
        this->A = A;
        this->B = B;
        vector<long> m1(A.size() + 1, -1);
        vector<int> m2(A.size() + 1, -1);
        dp(0, m1, m2);
        if (m1[0] == -1 || m1[0] > max) {
            return vector<int>();
        }
        vector<int> result;
        int idx = 0;
        result.push_back(idx + 1);
        while (idx != A.size() - 1) {
            idx = m2[idx];
            result.push_back(idx + 1);
        }
        return result;
    }

    long dp(int idx, vector<long>& m1, vector<int>& m2) {
        if (A[idx] == -1) {
            return INT_MAX;
        }
        if (m1[idx] != -1) {
            return m1[idx];
        }
        if (idx == A.size() - 1) {
            m1[idx] = A[idx];
            m2[idx] = idx;
            return A[idx];
        }
        long min = INT_MAX;
        int next = -1;
        for (int i = idx + 1; i < A.size() && i <= idx + B; i++) {
            long tmp = dp(i, m1, m2);
            tmp += A[i];
            if (tmp < min) {
                min = tmp;
                next = i;
            }
        }
        m1[idx] = min;
        m2[idx] = next;
        return min;
    }
};