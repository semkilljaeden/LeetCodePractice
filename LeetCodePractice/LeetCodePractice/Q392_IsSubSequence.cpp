#include<vector>
#include<string>
using namespace std;

//6:14 6:18 too easy
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Is Subsequence.
Memory Usage: 6.2 MB, less than 96.30% of C++ online submissions for Is Subsequence.
*/
class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) {
            return false;
        }
        if (s.size() == 0) {
            return true;
        }
        int k = 0;
        for (auto& x : t) {
            if (x == s[k]) {
                ++k;
            }
            if (k == s.size()) {
                return true;
            }
        }
        return false;
    }
};