#include "LCHeader.h"
//11:35 11:47 halt, will do a divide and conquer too a long while to get quicksort correct
/*
Runtime: 132 ms, faster than 97.04% of C++ online submissions for K Closest Points to Origin.
Memory Usage: 49.2 MB, less than 94.58% of C++ online submissions for K Closest Points to Origin.
*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        dc(points, 0, points.size() - 1, k);
        return vector<vector<int>>{points.begin(), points.begin() + k};
    }

    void dc(vector<vector<int>>& dis, int left, int right, int K) {
        if (left >= right) {
            return;
        }
        int mid = part(dis, left, right);
        int length = mid - left + 1;
        if (K < length) {
            dc(dis, left, mid - 1, K);
        }
        else if (K > length) {
            dc(dis, mid + 1, right, K - length);
        }
    }
    int part(vector<vector<int>>& dis, int left, int right) {
        int mid = rand() % (right - left) + left;
        int pivot = dist(dis[mid]);
        swap(dis[left], dis[mid]);
        int init = left;
        left++;
        while (true) {
            while (left < right && dist(dis[left]) < pivot) {
                left++;
            }
            while (left <= right && dist(dis[right]) >= pivot) {
                right--;
            }
            if (left >= right) {
                break;
            }
            swap(dis[left], dis[right]);
        }
        swap(dis[init], dis[right]);
        return right;

    }


    int dist(vector<int>& left) {
        return left[0] * left[0] + left[1] * left[1];
    }

};