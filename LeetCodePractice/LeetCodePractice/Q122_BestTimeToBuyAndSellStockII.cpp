#include<vector>
using namespace std;
//9:58 to 10:18 slow for easy question, one shot AC
/*
Runtime: 8 ms, faster than 92.97% of C++ online submissions for Best Time to Buy and Sell Stock II.
Memory Usage: 13.3 MB, less than 86.89% of C++ online submissions for Best Time to Buy and Sell Stock II.*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int result = 0;
        int prev = INT_MAX;
        int prevBought = -1;
        for (int& price : prices)
        {
            if (price < prev)
            {
                prevBought = price;
            }
            else if (price > prev)
            {
                result += price - prev;
            }
            prev = price;
        }
        return result;
    }
};