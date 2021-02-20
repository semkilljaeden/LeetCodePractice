#include<vector>
#include<string>
using namespace std;
/*
Runtime: 4 ms, faster than 97.76% of C++ online submissions for Unique Substrings in Wraparound String.
Memory Usage: 7.3 MB, less than 48.40% of C++ online submissions for Unique Substrings in Wraparound String
*/
//better solution
class Solution {
public:
    int findSubstringInWraproundString(string p) {
        if (p.size() == 0) {
            return 0;
        }
        vector<int> memo(26, 0);
        string buff;
        buff += p[0];
        memo[p[0] - 'a'] = 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26) {
                buff += p[i];
            }
            else {
                if (buff.size() > memo[buff[0] - 'a']) {
                    memo[buff[0] - 'a'] = buff.size();
                }
                buff.clear();
                buff += p[i];
            }
            if (memo[p[i] - 'a'] == 0) {
                memo[p[i] - 'a'] = 1;
            }
        }
        if (buff.size() > memo[buff[0] - 'a']) {
            memo[buff[0] - 'a'] = buff.size();
        }
        buff.clear();
        int result = 0;
        vector<int> r(memo);
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26 && j < memo[i]; j++) {
                if (memo[i] - j > r[(i + j) % 26]) {
                    r[(i + j) % 26] = memo[i] - j;
                }
            }
        }
        for (auto& x : r) {
            result += x;
        }
        return result;
    }
};

//12:24 1:14 too slow for medium, actually i have the algo, just took a bit long to implement

class Solution4 {
public:
    int findSubstringInWraproundString(string p) {
        if (p.size() == 0) {
            return 0;
        }
        vector<int> memo(26, 0);
        string buff;
        buff += p[0];
        memo[p[0] - 'a'] = 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] - 'a' == (p[i - 1] - 'a' + 1) % 26) {
                buff += p[i];
                for (int j = 0; j < 26 && j < buff.size(); j++) {
                    if (buff.size() - j > memo[(buff[0] - 'a' + j) % 26]) {
                        memo[(buff[0] - 'a' + j) % 26] = buff.size() - j;
                    }
                }
            }
            else {
                buff.clear();
                buff += p[i];
            }
            if (memo[p[i] - 'a'] == 0) {
                memo[p[i] - 'a'] = 1;
            }
        }
        int result = 0;
        for (auto& x : memo) {
            result += x;
        }
        return result;
    }
};

