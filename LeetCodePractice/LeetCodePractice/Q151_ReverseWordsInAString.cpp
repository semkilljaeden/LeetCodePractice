#include<vector>
#include<string>
using namespace std;
//5:33 : 6:17 O(n) in place
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Reverse Words in a String.
Memory Usage: 7.1 MB, less than 94.06% of C++ online submissions for Reverse Words in a String.
*/
class Solution {
public:
    string reverseWords(string s) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j)
        {
            char c = s[i];
            s[i] = s[j];
            s[j] = c;
            i++;
            j--;
        }
        i = 0;
        j = 0;
        int end = 0;
        //trim
        while (j < s.size())
        {
            while (s[j] == ' ' && j < s.size())
            {
                j++;
            }
            while (s[j] != ' ' && j < s.size())
            {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j++;
            }
            if (j < s.size())
            {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
                i++;
                j++;
            }
        }
        string k;
        k = s[i - 1] == ' ' ? s.substr(0, i - 1) : s.substr(0, i);
        //reverse
        i = 0;
        j = 0;
        end = 0;
        while (j < k.size())
        {
            while (k[j] != ' ' && j < k.size())
            {
                j++;
            }
            end = j;
            j--;
            while (i <= j)
            {
                char c = k[i];
                k[i] = k[j];
                k[j] = c;
                i++;
                j--;
            }
            i = end + 1;
            j = end + 1;
        }
        return k;
    }
};