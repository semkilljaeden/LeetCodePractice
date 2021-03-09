#include "LCHeader.h"
//8:36 9:22 read the answer, damn it
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Next Greater Element III.
Memory Usage: 6 MB, less than 95.50% of C++ online submissions for Next Greater Element III.
*/
class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        vector<int> stack;
        int left = -1;
        int right = -1;
        for (int i = s.size() - 1; i >= 0; i--) {
            while (stack.size() > 0 && s[i] < s[stack.back()]) {
                left = i;
                right = stack.back();
                stack.pop_back();
            }
            if (left != -1) {
                break;
            }
            stack.push_back(i);
        }
        if (left == -1) {
            return -1;
        }
        swap(s[left], s[right]);
        sort(s.begin() + left + 1, s.end(), std::less<char>());
        long result = stol(s);
        if (result > INT_MAX || result == n) {
            return -1;
        }
        return result;
    }
};