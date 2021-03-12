#include "LCHeader.h"
//2:12 2:58

class Solution {
public:
    int R;
    int C;
    vector<vector<int>> spiralMatrixIII(int R, int C, int r0, int c0) {
        this->R = R;
        this->C = C;
        vector<vector<int>> result;


        int level = 1;
        vector<vector<int>> step;


        vector<int> start{ r0, c0 };
        if (isInside(start)) {
            result.push_back(start);
        }
        start = vector<int>{ r0 + 1, c0 };

        while (result.size() < R * C) {
            if (step.size() == 0) {
                start[0]--;
                start[1]++;
                level += 2;
                step = pop(level);
                if (isInside(start)) {
                    result.push_back(start);
                }
                continue;
            }
            vector<int> tmp = start;
            for (int i = 0; i < step.size(); i++) {
                tmp[0] += step[i][0];
                tmp[1] += step[i][1];
                if (isInside(tmp)) {
                    result.push_back(tmp);
                }
            }
            step.clear();
        }
        return result;
    }

    inline bool isInside(vector<int>& start) {
        return start[0] >= 0 && start[0] < R && start[1] >= 0 && start[1] < C;
    }

    inline vector<vector<int>> pop(int size) {
        vector<vector<int>> result;
        for (int i = 0; i < size - 2; i++) {
            result.push_back(vector<int>{1, 0});
        }
        for (int i = 0; i < size - 1; i++) {
            result.push_back(vector<int>{0, -1});
        }
        for (int i = 0; i < size - 1; i++) {
            result.push_back(vector<int>{-1, 0});
        }
        for (int i = 0; i < size - 1; i++) {
            result.push_back(vector<int>{0, 1});
        }
        return result;
    }
};