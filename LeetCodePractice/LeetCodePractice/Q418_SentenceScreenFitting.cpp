#include<vector>
#include<string>
using namespace std;
//4:36 O(row)
/*
Runtime: 4 ms, faster than 96.55% of C++ online submissions for Sentence Screen Fitting.
Memory Usage: 7.5 MB, less than 70.85% of C++ online submissions for Sentence Screen Fitting.
*/

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int result = 0;
        int k = 0;
        vector<int> next(sentence.size() + 1, -1);
        vector<int> c(sentence.size() + 1, 0);

        for (int i = 0; i < rows; ++i) {
            if (next[k] != -1) {
                result += c[k];
                k = next[k];
                continue;
            }
            int j = 0;
            int count = 0;
            int kk = k;
            while (j < cols) {
                int ss = sentence[k].size();
                if (ss > cols) {
                    return 0;
                }
                if (j + ss <= cols) {
                    j += ss;
                    ++j;
                    ++k;
                    if (k == sentence.size()) {
                        ++count;
                        k = 0;
                    }
                }
                else {
                    break;
                }
            }
            next[kk] = k;
            c[kk] = count;
            result += count;
        }
        return result;
    }
};
//4:00 4:12 TLE

class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int count = 0;
        int k = 0;
        for (int i = 0; i < rows; ++i) {
            int j = 0;
            while (j < cols) {
                int ss = sentence[k].size();
                if (ss > cols) {
                    return 0;
                }
                if (j + ss <= cols) {
                    j += ss;
                    ++j;
                    ++k;
                    if (k == sentence.size()) {
                        ++count;
                        k = 0;
                    }
                }
                else {
                    break;
                }
            }
        }
        return count;
    }
};