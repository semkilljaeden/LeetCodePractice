#include "LCHeader.h"
//2:48 3:56 very funny merge sort

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        int count = 0;
        mergeSort(nums, 0, nums.size() - 1, count);
        return count;
    }

    void mergeSort(vector<int>& nums, int start, int end, int& count) {
        if (start >= end) {
            return;
        }
        int mid = (end - start) / 2 + start;
        mergeSort(nums, start, mid, count);
        mergeSort(nums, mid + 1, end, count);
        int j = mid + 1;
        for (int i = start; i <= mid; i++) {
            while (j <= end) {
                if ((long)nums[i] > 2LL * (long)nums[j]) {
                    count += mid - i + 1;
                    j++;
                }
                else {
                    break;
                }
            }
        }
        merge(nums, start, mid, end);
    }

    void merge(vector<int>& nums, int start, int mid, int end) {
        vector<int> left(nums.cbegin() + start, nums.cbegin() + mid + 1);
        vector<int> right(nums.cbegin() + mid + 1, nums.cbegin() + end + 1);
        int leftSize = mid - start + 1;
        int rightSize = end - mid;
        int l = 0;
        int r = 0;
        int i = start;
        while (l < leftSize && r < rightSize) {
            nums[i++] = left[l] <= right[r] ? left[l++] : right[r++];
        }
        while (l < leftSize) {
            nums[i++] = left[l++];
        }
        while (r < rightSize) {
            nums[i++] = right[r++];
        }
    }
};

