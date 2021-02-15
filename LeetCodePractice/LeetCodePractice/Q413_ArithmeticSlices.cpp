#include<vector>
using namespace std;
//11:37 12:01
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if (A.size() < 3) {
            return 0;
        }
        int sum = 0;
        int prev = 0;
        for (int i = 2; i < A.size(); i++) {
            if (A[i] - A[i - 1] == A[i - 1] - A[i - 2]) {
                int curr = prev + 1;
                prev = curr;
                sum += prev;
            }
            else {
                prev = 0;
            }
        }
        return sum;
    }
};