#include<vector>
using namespace std;
//1:10 read the answer

class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if (n == 0) {
            return 1;
        }
        if (n == 1) {
            return 10;
        }
        int sum = 91;
        int tmp = 9 * 9;
        int i = 2;
        while (i < n) {
            tmp *= 10 - i;
            sum += tmp;
            i++;
        }
        return sum;
    }
};