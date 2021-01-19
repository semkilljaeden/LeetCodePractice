#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int low = INT_MAX;
        int high = INT_MIN;
        int max = 0;
        for (int& price : prices)
        {
            if (price < low)
            {
                low = price;
            }
            if (price > high)
            {
                high = price;
            }
            if (price - low > max)
            {
                max = price - low;
            }
        }
        return max;
    }
};