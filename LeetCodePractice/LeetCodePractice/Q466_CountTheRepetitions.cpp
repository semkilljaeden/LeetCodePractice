#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//7:57 10:52, fianlly, too many bug to fix, the idea is correct initially
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Count The Repetitions.
Memory Usage: 6.3 MB, less than 88.99% of C++ online submissions for Count The Repetitions.

*/


class Solution {
public:
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        int size = s1.size() * n1;
        int s1s = s1.size();
        int s2s = s2.size();
        int i = 0;
        unordered_map<int, int> index;
        unordered_map<int, int> count;
        count[0] = 0;
        index[0] = 0;
        int prev = 0;
        int result = 0;
        int j = 0;
        while (i <= size) {
            if (j == s2s) {
                result++;
                j = 0;
                if (count.count(i % s1s) > 0) {
                    int loop_count = result - count[i % s1s];
                    int block = i - index[i % s1s];
                    result += (size - i) / block * loop_count;
                    i += (size - i) / block * block;
                    index.clear();
                    count.clear();
                }
                else {
                    count[i % s1s] = result;
                    index[i % s1s] = i;
                }
            }
            if (i == size) {
                break;
            }
            if (s1[i % s1s] == s2[j]) {
                j++;
            }
            i++;
        }
        return result / n2;
    }
};