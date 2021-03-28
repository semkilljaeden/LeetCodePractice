#include "LCHeader.h"
#include <queue>

//better solution, got idea of 132 problem


class Solution {//8:45 8:53
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int sum = 0;
        int n = arr.size();
        int end = 0;
        vector<int> tmp(n, 0);
        int prev = INT_MAX;
        int result = INT_MAX;
        int k = target;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            while (sum > k && end < i) {
                sum -= arr[end];
                end++;
            }
            if (sum == k) {
                tmp[i] = std::min(prev, i - end + 1);
                if (end > 0 && tmp[end - 1] != INT_MAX) {
                    result = std::min(result, i - end + 1 + tmp[end - 1]);
                }
            }
            else {
                tmp[i] = prev;
            }
            prev = tmp[i];
        }
        if (result == INT_MAX) {
            result = -1;
        }
        return result;
    }
};



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