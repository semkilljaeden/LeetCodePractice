#include "LCHeader.h"
#include<stack>
//10:10 too tedious
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Decode String.
Memory Usage: 6.5 MB, less than 82.81% of C++ online submissions for Decode String.
*/
class Solution {
public:
    string decodeString(string s) {
        return decode(s, 1);
    }

    string decode(string s, int k) {
        if (s == "") {
            return "";
        }
        string result;
        string tmp;
        int i = 0;
        while (i < s.size()) {
            int j = i;
            while (j < s.size() && !isdigit(s[j])) {
                j++;
            }
            result += s.substr(i, j - i);
            i = j;
            if (i == s.size()) {
                break;
            }
            while (isdigit(s[j])) {
                j++;
            }
            int count = 1;
            if (j > i) {
                count = stoi(s.substr(i, j - i));
            }
            stack<int> stack;
            stack.push(1);
            i = j;
            j = i + 1;
            while (stack.size() > 0) {
                if (s[j] == '[') {
                    stack.push(1);
                }
                else if (s[j] == ']') {
                    stack.pop();
                }
                j++;
            }
            result += decode(s.substr(i + 1, j - i - 2), count);

            i = j;
        }
        for (int i = 0; i < k; i++) {
            tmp += result;
        }
        return tmp;
    }
};