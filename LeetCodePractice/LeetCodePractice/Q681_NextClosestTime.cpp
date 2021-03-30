#include "LCHeader.h"
//8:56 9:09
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Closest Time.
Memory Usage: 6 MB, less than 54.76% of C++ online submissions for Next Closest Time.
*/

class Solution {
public:
    string nextClosestTime(string time) {
        unordered_set<char> set(time.cbegin(), time.cend());
        next(time);
        while (true) {
            bool pass = true;
            for (auto& x : time) {
                if (set.count(x) == 0) {
                    pass = false;
                }
            }
            if (pass) {
                return time;
            }
            next(time);
        }
    }

    void next(string& time) {
        if (time[4] < '9') {
            time[4]++;
            return;
        }
        if (time[4] == '9') {
            time[3]++;
            time[4] = '0';
        }
        bool add = false;
        if (time[3] == '6') {
            time[3] = '0';
            add = true;
        }
        if (!add) {
            return;
        }
        if (time[0] < '2') {
            if (time[1] == '9') {
                time[0]++;
                time[1] = '0';
            }
            else {
                time[1]++;
            }
        }
        else {
            if (time[1] == '3') {
                time[0] = '0';
                time[1] = '0';
            }
            else {
                time[1]++;
            }
        }
    }

};