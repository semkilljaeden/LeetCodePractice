#include<vector>
using namespace std;

//O(nk)
class Solution {
public:
    const int base = 1000000007;
    int kInversePairs(int n, int kk) {
        vector<int> m1(kk + 1, 0);
        vector<int> m2(kk + 1, 0);
        auto* mm1 = &m1;
        auto* mm2 = &m2;
        m1[0] = 1;
        for (int i = 1; i < n; i++) {
            auto& memo = *mm1;
            auto& cur = *mm2;
            int tmp = 0;
            int x = i + 1;
            for (int j = 0; j <= kk; j++) {
                if (x > 0) {
                    tmp += memo[j];
                    tmp %= base;
                    x--;
                }
                else {
                    tmp += memo[j];
                    tmp %= base;
                    tmp += (base - memo[j - i - 1]) % base;
                    tmp %= base;
                }
                cur[j] = tmp;
            }
            swap(mm1, mm2);
        }
        return (*mm1)[kk];
    }
};



//7:54, understand the question wrongly, actually the question is not hard
//O(n^2K) TLE
class Solution {
public:
    const int base = 1000000007;
    int kInversePairs(int n, int kk) {
        vector<int> m1(kk + 1, 0);
        vector<int> m2(kk + 1, 0);
        auto* mm1 = &m1;
        auto* mm2 = &m2;
        m1[0] = 1;
        for (int i = 0; i < n; i++) {
            auto& memo = *mm1;
            auto& cur = *mm2;
            for (int j = 0; j <= kk; j++) {
                cur[j] = 0;
            }
            for (int j = 0; j <= kk; j++) {
                for (int k = 0; k <= i; k++) {
                    if (j + k <= kk) {
                        cur[j + k] += memo[j];
                        cur[j + k] %= base;
                    }
                    else {
                        break;
                    }
                }
            }
            swap(mm1, mm2);
        }
        return (*mm1)[kk];
    }
};