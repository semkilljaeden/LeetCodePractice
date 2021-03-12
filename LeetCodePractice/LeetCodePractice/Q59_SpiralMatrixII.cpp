#include "LCHeader.h"
//3:09 3:23
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Spiral Matrix II.
Memory Usage: 6.6 MB, less than 51.28% of C++ online submissions for Spiral Matrix II.
*/
class Solution {//3:09 3:23
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        int count = n * n;
        int idx = 0;
        vector<vector<int>*> step;
        vector<int> start{ 0, -1 };
        int N = n + 2;
        while (idx < count) {
            if (step.size() == 0) {
                start[1]++;
                result[start[0]][start[1]] = idx + 1;
                idx++;
                N -= 2;
                step = comp(N);
                continue;
            }
            for (int i = 0; i < step.size(); i++) {
                start[0] += (*step[i])[0];
                start[1] += (*step[i])[1];
                result[start[0]][start[1]] = idx + 1;
                idx++;
            }
            step.clear();
        }
        return result;
    }

    vector<vector<int>*> comp(int n) {
        vector<vector<int>*> result;
        static vector<int> v1{ 0, 1 };
        static vector<int> v2{ 1, 0 };
        static vector<int> v3{ 0, -1 };
        static vector<int> v4{ -1, 0 };
        for (int i = 0; i < n - 1; i++) {
            result.push_back(&v1);
        }
        for (int i = 0; i < n - 1; i++) {
            result.push_back(&v2);
        }
        for (int i = 0; i < n - 1; i++) {
            result.push_back(&v3);
        }
        for (int i = 0; i < n - 2; i++) {
            result.push_back(&v4);
        }
        return result;
    }

};