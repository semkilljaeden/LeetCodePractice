#include "LCHeader.h"
#include "queue"
//12:53 1:04, a bit slow but very methodology

class Solution {
public:
    int calculate(string s) {
        queue<string> q;
        for (int i = 0; i < s.size();) {
            if (isdigit(s[i])) {
                string tmp;
                while (isdigit(s[i])) {
                    tmp += s[i];
                    i++;
                }
                q.push(tmp);
                continue;
            }
            else if (s[i] == ' ') {
            }
            else {
                q.push(string{ s[i] });
            }
            i++;
        }
        return rec(q);
    }

    int rec(queue<string>& q) {
        int sum = 0;
        string ops = "+";
        while (q.size() > 0) {
            string s = q.front();
            q.pop();
            if (isOps(s)) {
                ops = s;
            }
            else if (s == ")") {
                return sum;
            }
            else {
                int num = 0;
                if (s == "(") {
                    num = rec(q);
                }
                else {
                    num = stoi(s);
                }
                if (ops == "+") {
                    sum += num;
                }
                else {
                    sum -= num;
                }
            }
        }
        return sum;
    }

    bool isOps(const string& s) {
        return s == "+" || s == "-";
    }
};
