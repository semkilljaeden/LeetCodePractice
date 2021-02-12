#include<vector>
#include<queue>
//8:04 8:34
using namespace std;
/*
Runtime: 60 ms, faster than 31.00% of C++ online submissions for Ugly Number II.
Memory Usage: 8.4 MB, less than 52.06% of C++ online submissions for Ugly Number II.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        auto cmp = [](int left, int right) { return left > right; };
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        pq.push(1);
        int r = 0;
        while (n > 0) {
            int tmp = pq.top();
            if (tmp <= r) {
                pq.pop();
                continue;
            }
            r = tmp;
            pq.pop();
            if (INT_MAX / 2 > r) pq.push(r * 2);
            if (INT_MAX / 3 > r) pq.push(r * 3);
            if (INT_MAX / 5 > r) pq.push(r * 5);
            n--;
        }
        return r;
    }
};