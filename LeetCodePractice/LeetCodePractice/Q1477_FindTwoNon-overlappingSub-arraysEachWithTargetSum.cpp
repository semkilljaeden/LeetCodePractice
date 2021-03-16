#include "LCHeader.h"
#include <queue>
//5:31 6:20 WTF, the boundary check is so tedious

class Solution {
public:
    const int limit = 10000000;
    int minSumOfLengths(vector<int>& arr, int target) {
        int result = 100000000;
        int n = arr.size();


        int head = 0;
        int tail = 0;
        int sum = 0;
        queue<pair<int, int>> q;
        int prev = limit;

        for (; head < n; head++) {
            sum += arr[head];
            while (sum > target && tail < head) {
                sum -= arr[tail];
                tail++;
                if (q.size() > 0 && tail > q.front().first) {
                    prev = std::min(prev, q.front().second);
                    q.pop();
                }
            }
            if (sum == target) {
                result = std::min(result, head - tail + 1 + prev);
                q.push(make_pair(head, head - tail + 1));
            }
        }
        head--;
        if (sum == target) {
            result = std::min(result, head - tail + 1 + prev);
            q.push(make_pair(head, head - tail + 1));
        }
        if (result >= limit) {
            result = -1;
        }
        return result;
    }
};