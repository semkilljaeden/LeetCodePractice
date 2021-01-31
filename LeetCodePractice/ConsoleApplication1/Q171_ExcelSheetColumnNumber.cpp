#include<vector>
#include<string>
using namespace std;
//12:05 12:12 used debugger
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Excel Sheet Column Number.
Memory Usage: 6 MB, less than 85.80% of C++ online submissions for Excel Sheet Column Number.
*/
class Solution {
public:
    int titleToNumber(string s) {
        int m = 0;
        int result = 0;
        for (int i = s.size() - 1; i >= 0; i--)
        {
            result += (s[i] - 'A' + 1) * pow(26, m++);
        }
        return result;
    }
};