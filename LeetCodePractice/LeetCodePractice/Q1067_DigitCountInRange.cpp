#include "LCHeader.h"
//5:29 Ultimate Template
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Digit Count in Range.
Memory Usage: 7 MB, less than 9.38% of C++ online submissions for Digit Count in Range.
*/
class Solution { //3:57 4;13 halt 4:42 5:27, 
public:
    int D;
    int digitsCount(int d, int low, int high) {
        D = d;
        string ceil = to_string(high);
        string floor = to_string(low);
        floor = string(ceil.size() - floor.size(), '0') + floor;
        vector<vector<vector<vector<vector<int>>>>> memo(ceil.size(), vector<vector<vector<vector<int>>>>(2, vector<vector<vector<int>>>(2, vector<vector<int>>(2, vector<int>(ceil.size() + 1, -1)))));
        return dp(ceil, floor, 0, 1, 1, 1, 0, memo);
    }


    int dp(string& ceil, string& floor, int idx, int cLimit, int fLimit, int leadingZero, int count, vector<vector<vector<vector<vector<int>>>>>& memo) {
        if (idx == ceil.size()) {
            return count;
        }
        if (memo[idx][cLimit][fLimit][leadingZero][count] != -1) {
            return memo[idx][cLimit][fLimit][leadingZero][count];
        }
        int start = fLimit == 1 ? floor[idx] - '0' : 0;
        int end = cLimit == 1 ? ceil[idx] - '0' : 9;
        int sum = 0;
        for (int i = start; i <= end; i++) {
            int newLeadingZero = i == 0 && leadingZero == 1 ? 1 : 0;
            int newClimit = cLimit == 1 && i == end ? 1 : 0;
            int newFlimit = fLimit == 1 && i == start ? 1 : 0;
            int newCount = i == D ? 1 : 0;
            if (i == 0 && D == 0 && leadingZero) {
                newCount = 0;
            }
            sum += dp(ceil, floor, idx + 1,
                newClimit,
                newFlimit,
                newLeadingZero, count + newCount, memo);
        }
        return memo[idx][cLimit][fLimit][leadingZero][count] = sum;
    }
};