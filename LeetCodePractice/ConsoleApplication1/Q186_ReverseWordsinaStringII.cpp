#include<vector>
using namespace std;
//2:19 2:26
/*
Runtime: 16 ms, faster than 99.16% of C++ online submissions for Reverse Words in a String II.
Memory Usage: 17.3 MB, less than 79.11% of C++ online submissions for Reverse Words in a String II.
*/
class Solution {
public:
    void reverseWords(vector<char>& s) {
        reverse(s.begin(), s.end());
        auto left = s.begin();
        auto right = s.begin();
        while (true)
        {
            while (right != s.end() && *right != ' ')
            {
                right++;
            }
            reverse(left, right);
            if (right == s.end())
            {
                return;
            }
            left = ++right;
        }
    }
};
