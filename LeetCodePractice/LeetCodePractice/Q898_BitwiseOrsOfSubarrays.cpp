#include "LCHeader.h"
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> set;
        int t = 0;
        for (auto& x : arr) {
            t |= x;
        }
        for (int i = 0; i < arr.size(); i++) {
            int x = arr[i];
            for (int j = i; j < arr.size(); j++) {
                x |= arr[j];
                if (set.count(x) == 0) {
                    set.insert(x);
                }
                if (x == t) {
                    break;
                }
            }
        }
        return set.size();
    }
};