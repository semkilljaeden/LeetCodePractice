#include "LCHeader.h"
//12:56 1:12. 16mins AC
/*
Runtime: 4 ms, faster than 91.76% of C++ online submissions for Champagne Tower.
Memory Usage: 6.6 MB, less than 54.55% of C++ online submissions for Champagne Tower.
*/
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> p(100, 0);
        vector<double> c(100, 0);
        p[0] = poured;
        auto* p1 = &p;
        auto* c1 = &c;
        for (int i = 0; i < query_row; i++) {
            auto& prev = *p1;
            auto& cur = *c1;
            std::fill(cur.begin(), cur.end(), 0);
            for (int j = 0; j < query_row; j++) {
                if (prev[j] < 1) {
                    continue;
                }
                double excess = prev[j] - 1;
                cur[j] += excess / 2;
                cur[j + 1] += excess / 2;
            }
            swap(p1, c1);
        }
        for (auto& x : *p1) {
            if (x > 1) {
                x = 1;
            }
        }
        return (*p1)[query_glass];
    }
};