#include<vector>
#include<string>
using namespace std;


//O(n^2)
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for (int i = 1; i <= s.size() / 2; i++) {
            if (s.size() % i != 0) {
                continue;
            }
            int x = 0;
            bool c = true;
            while (x < s.size()) {
                if (s.substr(x, i) != s.substr(0, i)) {
                    c = false;
                    break;
                }
                x += i;
            }
            if (c) {
                return true;
            }
        }
        return false;
    }
};