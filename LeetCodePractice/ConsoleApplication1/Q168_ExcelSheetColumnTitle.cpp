#include<vector>
#include<string>
using namespace std;
//6:05 6:17 too slow for an easy
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Title.
Memory Usage: 5.7 MB, less than 99.72% of C++ online submissions for Excel Sheet Column Title.
*/
class Solution {
public:
    string convertToTitle(int n) {
        string s;
        s += --n % 26 + 'A';
        while ((n /= 26) > 0)
        {
            s += --n % 26 + 'A';
        }
        reverse(s.begin(), s.end());
        return s;
    }
};