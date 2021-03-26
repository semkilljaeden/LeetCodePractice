#include "LCHeader.h"
//12:40 12:51 AC~~

class Solution {
public:
    int scoreOfParentheses(string S) {
        vector<int> stack;
        for (int i = 0; i < S.size(); i++) {
            auto& c = S[i];
            if (c == '(') {
                if (stack.size() > 0 && stack.back() > 0) {
                    stack.back()++;
                }
                else {
                    stack.push_back(1);
                }
            }
            else if (c == ')') {
                if (stack.back() < 0) {
                    int num = 0;
                    while (stack.back() < 0) {
                        num += stack.back();
                        stack.pop_back();
                    }
                    stack.back()--;
                    if (stack.back() == 0) {
                        stack.pop_back();
                    }
                    stack.push_back(num * 2);
                }
                else {
                    stack.back()--;
                    if (stack.back() == 0) {
                        stack.pop_back();
                    }
                    stack.push_back(-1);
                }
            }
        }
        int result = 0;
        for (auto& x : stack) {
            result += x;
        }
        return abs(result);
    }
};