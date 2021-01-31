#include<vector>
#include<unordered_set>
using namespace std;
//4:34 4:39 ok for an easy
/*
Runtime: 4 ms, faster than 54.52% of C++ online submissions for Happy Number.
Memory Usage: 6.4 MB, less than 53.74% of C++ online submissions for Happy Number.
*/
class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> set;
        int tmp = 0;
        while (set.count(n) == 0)
        {
            set.insert(n);
            tmp = 0;
            int i = 0;
            while (n > 0)
            {
                tmp += pow(n % 10, 2);
                n /= 10;
            }
            if (tmp == 1)
            {
                return true;
            }
            n = tmp;
        }
        return false;
    }
};