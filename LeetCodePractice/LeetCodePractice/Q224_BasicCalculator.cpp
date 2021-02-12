#include<string>
#include<vector>
#include<unordered_set>
using namespace std;
//11:19 to 12:05 46mins for an easy-hard question, ok
/*
Runtime: 16 ms, faster than 52.07% of C++ online submissions for Basic Calculator.
Memory Usage: 8.3 MB, less than 72.00% of C++ online submissions for Basic Calculator.
*/
class Solution {
public:
    unordered_set<char> se{ '+', '-' };
    int calculate(string s) {
        int i = 0;
        int count = 0;
        return c(s, i, count);
    }
    int c(string& s, int& i, int& count) {
        int sum = 0;
        char action = '+';
        if (s[i] == '-') {
            action = '-';
            i++;
        }
        string tmp;
        int x = 0;
        while (i < s.size()) {
            if (s[i] == ' ') {
            }
            else if (s[i] == ')') {
                count--;
                tmp.size() > 0 ? cal(sum, tmp, action) : cal(sum, x, action);
                i++;
                return sum;
            }
            else if (se.count(s[i]) > 0) {
                tmp.size() > 0 ? cal(sum, tmp, action) : cal(sum, x, action);
                tmp.clear();
                action = s[i];
            }
            else if (isdigit(s[i])) {
                tmp += s[i];
            }
            else if (s[i] == '(') {
                x = c(s, ++i, ++count);
                i--;
            }
            i++;
        }
        tmp.size() > 0 ? cal(sum, tmp, action) : cal(sum, x, action);
        return sum;
    }

    void cal(int& sum, string& tmp, char action) {
        cal(sum, stoi(tmp), action);
    }

    void cal(int& sum, int tmp, char action) {
        action == '+' ? sum += tmp : sum -= tmp;
    }
};