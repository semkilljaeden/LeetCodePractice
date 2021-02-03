#include<vector>
using namespace std;

//10:51 to 11:23
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Combination Sum III.
Memory Usage: 6.7 MB, less than 65.39% of C++ online submissions for Combination Sum III.
*/
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        vector<vector<int>> result;
        cb3(1, k, n, tmp, result);
        return result;
    }

    void cb3(int i, int k, int n, vector<int>& tmp, vector<vector<int>>& result)
    {
        if (k == 0)
        {
            if (n == 0)
            {
                result.push_back(tmp);
                return;
            }
            return;
        }
        if (n < i)
        {
            return;
        }
        if (i > 9)
        {
            return;
        }
        cb3(i + 1, k, n, tmp, result);
        tmp.push_back(i);
        cb3(i + 1, k - 1, n - i, tmp, result);
        tmp.erase(tmp.end() - 1, tmp.end());
        return;
    }
};