#include "LCHeader.h"
//1:05
/*Runtime: 360 ms, faster than 58.48% of C++ online submissions for Campus Bikes.
Memory Usage: 23.4 MB, less than 98.77% of C++ online submissions for Campus Bikes.

*/

class Solution {//12:04
public:

    class P {
    public:
        int distance;
        int worker;
        int bike;

        bool operator<(const P& rhs) const {
            if (distance == rhs.distance) {
                if (worker == rhs.worker) {
                    return bike < rhs.bike;
                }
                return worker < rhs.worker;
            }
            return distance < rhs.distance;
        }
    };

    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> result(workers.size(), -1);
        vector<P> buff;
        buff.reserve(workers.size() * bikes.size());
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                buff.push_back({ dis(workers[i], bikes[j]), i, j });
            }
        }
        sort(buff.begin(), buff.end());
        int count = workers.size();
        vector<int> used(bikes.size(), -1);
        int idx = 0;
        while (count > 0) {
            auto& tmp = buff[idx];
            if (result[tmp.worker] == -1 && used[tmp.bike] == -1) {
                result[tmp.worker] = tmp.bike;
                used[tmp.bike] = 0;
                count--;
            }
            idx++;
        }
        return result;
    }

    static inline int dis(const vector<int>& left, const vector<int>& right) {
        return abs(left[0] - right[0]) + abs(left[1] - right[1]);
    }
};


//12:04 12:53 failed. O(MNlog(MN)) costly comparator
class Solution {//12:04
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        vector<int> result(workers.size(), -1);
        auto cmp = [&workers, &bikes](const vector<int>& left, const vector<int>& right) {
            int left_dis = Solution::dis(workers[left[0]], bikes[left[1]]);
            int right_dis = Solution::dis(workers[right[0]], bikes[right[1]]);
            if (left_dis == right_dis) {
                if (left[0] == right[0]) {
                    return left[1] < right[1];
                }
                return left[0] < right[0];
            }
            return left_dis < right_dis;
        };
        vector<vector<int>> buff(workers.size() * bikes.size(), vector<int>(2, 0));
        int count = 0;
        for (int i = 0; i < workers.size(); i++) {
            for (int j = 0; j < bikes.size(); j++) {
                buff[count][0] = i;
                buff[count][1] = j;
                count++;
            }
        }
        sort(buff.begin(), buff.end(), cmp);
        count = workers.size();
        vector<int> used(bikes.size(), -1);
        int idx = 0;
        while (count > 0) {
            auto& tmp = buff[idx];
            if (result[tmp[0]] == -1 && used[tmp[1]] == -1) {
                result[tmp[0]] = tmp[1];
                used[tmp[1]] = 0;
                count--;
            }
            idx++;
        }
        return result;
    }

    static inline int dis(const vector<int>& left, const vector<int>& right) {
        return abs(left[0] - right[0]) + abs(left[1] - right[1]);
    }
};