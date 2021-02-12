#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

//6:14 8:00, stop in between but still too slow

class Solution {
public:
    unordered_set<char> ac{ '-', '+', '*', '/' };
    int calculate(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int sum = 0;
        int i = 0;
        char sign = next_sign(i, s) == '-' ? '-' : '+';
        int tmp = next_int(i, s);
        int curr = tmp;
        while (i < s.size()) {
            char csign = next_sign(i, s);
            tmp = next_int(i, s);
            if (csign == '+' || csign == '-') {
                cal(sum, curr, sign);
                sign = csign;
                curr = tmp;
            }
            else {
                cal(curr, tmp, csign);
            }
        }
        cal(sum, curr, sign);
        return sum;
    }

    char next_sign(int& i, string& s) {
        while (s[i] == ' ') {
            i++;
        }
        if (i >= s.size()) {
            return '0';
        }
        if (ac.count(s[i]) > 0) {
            return s[i++];
        }
        return '0';
    }
    int next_int(int& i, string& s) {
        int r = 0;
        while (s[i] == ' ') {
            i++;
        }
        if (i >= s.size()) {
            return r;
        }
        while (i < s.size() && isdigit(s[i])) {
            r *= 10;
            r += s[i] - '0';
            i++;
        }
        return r;
    }

    void cal(int& sum, int v, char sign) {
        if (sign == '-') {
            sum -= v;
        }
        else if (sign == '+') {
            sum += v;
        }
        else if (sign == '*') {
            sum *= v;
        }
        else if (sign == '/') {
            sum /= v;
        }
    }
};