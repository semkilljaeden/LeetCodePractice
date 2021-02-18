#include<vector>
#include<string>
#include<unordered_map>
using namespace std;

//2:07 6:43, damn wtf, hard question

class Solution {
public:
    unordered_map<string, string> memo;
    string encode(string s) {
        return trim(s);
    }

    string trim(string s) {
        if (s.size() < 5) {
            return s;
        }
        if (memo.find(s) != memo.end()) {
            return memo[s];
        }
        string best = s;
        string tmp = has_rep(s);
        if (tmp != "") {
            int count = s.size() / tmp.size();
            tmp = trim(tmp);
            best = move(to_string(count) + "[" + tmp + "]");
        }
        else {
            for (int i = 1; i <= s.size() - 1; i++) {
                string&& tt = trim(s.substr(0, i)) + trim(s.substr(i, s.size() - i));
                if (tt.size() < best.size()) {
                    best = move(tt);
                }

            }
        }
        return memo[s] = best;
    }

    string has_rep(string& s) {
        for (int i = 1; i <= s.size() / 2; i++) {
            if (s.size() % i != 0) {
                continue;
            }
            bool x = true;
            for (int j = 0; j + i <= s.size();) {
                if (s.substr(j, i) != s.substr(0, i)) {
                    x = false;
                    break;
                }
                j += i;
            }
            if (x) {
                return s.substr(0, i);
            }
        }
        return "";
    }
};