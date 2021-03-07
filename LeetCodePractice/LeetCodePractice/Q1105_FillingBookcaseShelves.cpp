#include "LCHeader.h"
//silly!!! memo does not need the prev! but why?

class Solution {
public:
    int Width;
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        Width = shelf_width;
        vector<vector<int>> memo(books.size(), vector<int>(1001, -1));
        return dp(books, 0, 0, 0, memo);
    }

    int dp(vector<vector<int>>& books, int shelf_width, int idx, int prev, vector<vector<int>>& memo) {
        if (idx == books.size()) {
            return prev;
        }
        if (memo[idx][shelf_width] != -1) {
            return memo[idx][shelf_width];
        }
        auto& cur = books[idx];
        int& width = cur[0];
        int& height = cur[1];
        int h1 = prev + dp(books, Width - width, idx + 1, height, memo);
        int h2 = INT_MAX;
        if (width <= shelf_width) {
            h2 = dp(books, shelf_width - width, idx + 1, max(prev, height), memo);
        }
        return memo[idx][shelf_width] = min(h1, h2);
    }
};

//7:18 7: 48 TLE
class Solution {
public:
    int Width;
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        Width = shelf_width;
        vector<vector<vector<int>>> memo(books.size(), vector<vector<int>>(1001, vector<int>(1001, -1)));
        return dp(books, 0, 0, 0, memo);
    }

    int dp(vector<vector<int>>& books, int shelf_width, int idx, int prev, vector<vector<vector<int>>>& memo) {
        if (idx == books.size()) {
            return prev;
        }
        if (memo[idx][shelf_width][prev] != -1) {
            return memo[idx][shelf_width][prev];
        }
        auto& cur = books[idx];
        int& width = cur[0];
        int& height = cur[1];
        int h1 = prev + dp(books, Width - width, idx + 1, height, memo);
        int h2 = INT_MAX;
        if (width <= shelf_width) {
            h2 = dp(books, shelf_width - width, idx + 1, max(prev, height), memo);
        }
        return memo[idx][shelf_width][prev] = min(h1, h2);
    }
};