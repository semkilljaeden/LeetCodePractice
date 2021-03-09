#include "LCHeader.h"

/*
Runtime: 12 ms, faster than 77.56% of C++ online submissions for Longest Substring with At Most K Distinct Characters.
Memory Usage: 8.2 MB, less than 42.68% of C++ online submissions for Longest Substring with At Most K Distinct Characters.
*/

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> map;
        int left = 0;
        int right = 0;
        int count = 0;
        for (; right < s.size(); right++) {
            map[s[right]]++;
            if (map.size() > k) {
                while (map.size() > k) {
                    map[s[left]]--;
                    if (map[s[left]] == 0) {
                        map.erase(s[left]);
                    }
                    left++;
                }
            }
            count = std::max(count, right - left + 1);
        }
        return count;
    }
};