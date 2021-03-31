#include "LCHeader.h"
//1:10mins


class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        auto cmp = [](const vector<int>& left, const vector<int>& right) {
            if (left[0] == right[0]) {
                return left[1] < right[1];
            }
            return left[0] < right[0];
        };
        sort(people.begin(), people.end(), cmp);
        vector<vector<int>> result(people.size(), vector<int>{-1, -1});
        int cur = -1;
        int base = 0;
        for (auto& x : people) {
            int count = x[1];
            int i = 0;
            for (; i < result.size(); i++) {
                if (count == 0) {
                    if (result[i][0] == -1 && result[i][1] == -1) {
                        break;
                    }
                    else {
                        continue;
                    }
                }
                if (result[i][0] >= x[0]) {
                    count--;
                }
                else if (result[i][0] == -1) {
                    count--;
                }
            }
            result[i] = x;
        }
        return result;
    }
};