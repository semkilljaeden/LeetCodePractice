#include "LCHeader.h"
//3:19 3:38 TLE 3:41 pass WTF

/*
Runtime: 352 ms, faster than 65.87% of C++ online submissions for Triples with Bitwise AND Equal To Zero.
Memory Usage: 12.9 MB, less than 58.68% of C++ online submissions for Triples with Bitwise AND Equal To Zero.
*/

class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> map;
        int count = 0;
        for (int i = 0; i < A.size(); i++) {
            for (int j = i; j < A.size(); j++) {
                int tmp = A[i] & A[j];
                int c = 0;
                if (map.count(tmp) > 0) {
                    c = map[tmp];
                }
                else {
                    for (int k = 0; k < A.size(); k++) {
                        if ((tmp & A[k]) == 0) {
                            c++;
                        }
                    }
                    map[tmp] = c;
                }
                count += c * (i == j ? 1 : 2);
            }
        }
        return count;
    }
};