#include "LCHeader.h"


int largestRectangleArea(vector<int>& heights) {
    vector<int> stack;
    stack.reserve(heights.size());
    stack.push_back(-1);
    int result = 0;
    for (int i = 0; i < heights.size(); i++) {
        int idx = i;
        while (stack.back() != -1 && heights[stack.back()] >= heights[i]) {
            idx = stack.back();
            stack.pop_back();
            int width = i - stack.back() - 1;
            result = std::max(result, width * heights[idx]);
        }
        int width = i - stack.back();
        result = std::max(result, width * heights[i]);
        stack.push_back(i);
    }
    while (stack.size() > 1) {
        int idx = stack.back();
        stack.pop_back();
        int width = heights.size() - stack.back() - 1;
        result = std::max(result, width * heights[idx]);
    }
    return result;
}


/*
Runtime: 220 ms, faster than 15.56% of C++ online submissions for Largest Rectangle in Histogram.
Memory Usage: 84.6 MB, less than 5.02% of C++ online submissions for Largest Rectangle in Histogram.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<vector<int>> stack{ {0, 0} };
        int result = 0;
        for (int i = 0; i < heights.size(); i++) {
            int size = 1;
            while (stack.size() > 0 && stack.back()[0] >= heights[i]) {
                size = std::max(size, stack.back()[1] + 1);
                stack.pop_back();
            }
            for (auto& x : stack) {
                result = std::max(result, x[0] * (++x[1]));
            }
            result = std::max(result, size * heights[i]);
            stack.push_back(vector<int>{heights[i], size});
        }
        return result;
    }
};