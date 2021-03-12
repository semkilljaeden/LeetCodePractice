#include "LCHeader.h"
#include <queue>
#include <stack>
//12:54

class Solution {//2:00 2:47
public:
    int calculate(string s) {
        queue<string> q;
        for (int i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                string x;
                while (i < s.size() && isdigit(s[i])) {
                    x += s[i];
                    i++;
                }
                q.push(x);
            }
            else {
                q.push(string{ s[i] });
                i++;
            }
        }
        return cal(q, false);
    }

    int cal(queue<string>& q, bool bracket) {
        stack<double> stack;
        double digit;
        if (q.front() == "(") {
            q.pop();
            digit = cal(q, true);
        }
        else {
            digit = stod(q.front());
            q.pop();
        }
        stack.push(digit);
        string ops;
        while (q.size() > 0) {
            if (q.front() == ")" && bracket) {
                q.pop();
                break;
            }
            if (!isOps(q.front())) {
                double digit;
                if (q.front() == "(") {
                    q.pop();
                    digit = cal(q, true);
                    int x = 1;
                }
                else {
                    digit = stod(q.front());
                    q.pop();
                }
                if (ops == "+") {
                    stack.push(digit);
                }
                else if (ops == "-") {
                    stack.push(-digit);
                }
                else if (ops == "*") {
                    auto tmp = stack.top() * digit;
                    stack.pop();
                    stack.push(tmp);
                }
                else if (ops == "/") {
                    auto tmp = stack.top() / digit;
                    stack.pop();
                    stack.push(tmp);
                }
            }
            else {
                ops = q.front();
                q.pop();
            }
        }
        int sum = 0;
        while (stack.size() > 0) {
            sum += (int)stack.top();
            stack.pop();
        }
        return sum;
    }

    inline bool isOps(const string& s) {
        return s[0] == '+' || s[0] == '-' || s[0] == '*' || s[0] == '/';
    }
};