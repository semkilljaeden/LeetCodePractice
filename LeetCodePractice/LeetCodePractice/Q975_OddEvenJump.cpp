#include "LCHeader.h"
#include "set"
//5:29 6:03 O(nlogn)

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        set<int> tree;
        unordered_map<int, int> valueMap;
        vector<int> biggestSmaller(n);
        unordered_map<int, int> sbValueMap;
        vector<int> smallestBigger(n);
        for (int i = n - 1; i >= 0; i--) {
            tree.insert(arr[i]);
            if (valueMap.count(arr[i]) > 0) {
                biggestSmaller[i] = valueMap[arr[i]];
                smallestBigger[i] = valueMap[arr[i]];
            }
            else {
                auto itr = tree.lower_bound(arr[i]);
                int bs = itr != tree.begin() ? *std::prev(itr) : -1;
                biggestSmaller[i] = (bs != -1 ? valueMap[bs] : -1);
                itr = tree.upper_bound(arr[i]);
                bs = itr != tree.end() ? *itr : -1;
                smallestBigger[i] = (bs != -1 ? valueMap[bs] : -1);
            }
            valueMap[arr[i]] = i;
        }
        vector<vector<int>> memo(n, vector<int>(2, -1));
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dp(i, 0, biggestSmaller, smallestBigger, memo) == 1) {
                count++;
            }
        }
        return count;

    }

    int dp(int idx, int jump, vector<int>& biggestSmaller, vector<int>& smallestBigger, vector<vector<int>>& memo) {
        if (idx == -1) {
            return 0;
        }
        if (idx == biggestSmaller.size() - 1) {
            return 1;
        }
        if (memo[idx][jump % 2] != -1) {
            return memo[idx][jump % 2];
        }
        return memo[idx][jump % 2] = dp(jump % 2 == 0 ? smallestBigger[idx] : biggestSmaller[idx], jump + 1, biggestSmaller, smallestBigger, memo);
    }
};

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        set<int> tree;
        unordered_map<int, int> valueMap;
        vector<int> biggestSmaller(n);
        unordered_map<int, int> sbValueMap;
        vector<int> smallestBigger(n);
        for (int i = n - 1; i >= 0; i--) {
            tree.insert(arr[i]);
            if (valueMap.count(arr[i]) > 0) {
                biggestSmaller[i] = valueMap[arr[i]];
                smallestBigger[i] = valueMap[arr[i]];
            }
            else {
                auto itr = tree.lower_bound(arr[i]);
                int bs = itr != tree.begin() ? *std::prev(itr) : -1;
                biggestSmaller[i] = (bs != -1 ? valueMap[bs] : -1);
                itr = tree.upper_bound(arr[i]);
                bs = itr != tree.end() ? *itr : -1;
                smallestBigger[i] = (bs != -1 ? valueMap[bs] : -1);
            }
            valueMap[arr[i]] = i;
        }

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (dp(i, 0, biggestSmaller, smallestBigger) == 1) {
                count++;
            }
        }
        return count;

    }

    int dp(int idx, int jump, vector<int>& biggestSmaller, vector<int>& smallestBigger) {
        if (idx == -1) {
            return 0;
        }
        if (idx == biggestSmaller.size() - 1) {
            return 1;
        }
        return dp(jump % 2 == 0 ? smallestBigger[idx] : biggestSmaller[idx], jump + 1, biggestSmaller, smallestBigger);
    }
};