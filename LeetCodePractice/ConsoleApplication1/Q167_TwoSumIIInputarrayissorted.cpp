#include<vector>
#include<string>
using namespace std;
//5:47 to 5:52
/*
Runtime: 4 ms, faster than 96.63% of C++ online submissions for Two Sum II - Input array is sorted.
Memory Usage: 9.6 MB, less than 81.24% of C++ online submissions for Two Sum II - Input array is sorted.
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0; 
        int j = numbers.size() - 1;
        int tmp = 0;
        while (i < j)
        {
            tmp = numbers[i] + numbers[j];
            if (tmp == target)
            {
                return vector<int>{i + 1, j + 1};
            }
            else if (tmp < target)
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return vector<int>();
    }
};