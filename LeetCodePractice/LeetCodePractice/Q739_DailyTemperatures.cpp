#include "LCHeader.h"
//8:17 8:31, read the tips

/*
Runtime: 36 ms, faster than 99.97% of C++ online submissions for Daily Temperatures.
Memory Usage: 41.5 MB, less than 52.92% of C++ online submissions for Daily Temperatures.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> q;
        vector<int> result(T.size(), 0);
        for (int i = 0; i < T.size(); i++) {
            while (q.size() > 0 && T[q.back()] < T[i]) {
                result[q.back()] = i - q.back();
                q.pop_back();
            }
            q.push_back(i);
        }
        while (q.size() > 0) {
            result[q.back()] = 0;
            q.pop_back();
        }
        return result;
    }
};

/*
Runtime: 60 ms, faster than 81.38% of C++ online submissions for Daily Temperatures.
Memory Usage: 41.5 MB, less than 46.62% of C++ online submissions for Daily Temperatures.
*/
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {

    }
};