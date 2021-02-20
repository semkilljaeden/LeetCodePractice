#include<vector>
using namespace std;

//7:50 8:59 read the answer
/*
Runtime: 8 ms, faster than 90.28% of C++ online submissions for Super Washing Machines.
Memory Usage: 13.1 MB, less than 44.44% of C++ online submissions for Super Washing Machines.
*/
class Solution {
public:
    int findMinMoves(vector<int>& m) {
        int n = m.size();
        vector<int> sum(n + 1, 0);
        for (int i = 1; i < sum.size(); i++) {
            sum[i] += sum[i - 1] + m[i - 1];
        }
        if (sum.back() % n != 0) {
            return -1;
        }
        int avg = sum.back() / n;
        int result = 0;
        for (int i = 1; i < n + 1; i++) {
            int el = (i - 1) * avg;
            int al = sum[i - 1];
            int ar = sum.back() - sum[i];
            int er = (n - i) * avg;
            int t_r = std::max(abs(al - el), abs(ar - er));
            t_r = std::max(t_r, m[i - 1] - avg);
            result = std::max(result, t_r);
        }
        return result;
    }
};