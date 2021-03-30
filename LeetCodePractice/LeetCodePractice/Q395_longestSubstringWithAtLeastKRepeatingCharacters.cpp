#include "LCHeader.h"
//11:32 11:55, bugs


class Solution {//11:32
public:
    int longestSubstring(string s, int k) {
        if (k == 1) {
            return s.size();
        }
        if (s == "") {
            return 0;
        }
        int n = s.size();
        vector<vector<int>> cum(n, vector<int>(26, 0));
        vector<int> pos(26, 0);
        cum[0][s[0] - 'a']++;
        int result = 0;
        for (int i = 1; i < n; i++) {
            cum[i] = cum[i - 1];
            cum[i][s[i] - 'a']++;
            int latest = -1;
            pos[s[i] - 'a'] = i;
            for (int j = 0; j < 26; j++) {
                if (cum[i][j] == 0 || cum[i][j] >= k) {
                    continue;
                }
                else {
                    latest = std::max(latest, pos[j]);
                }
            }
            if (latest != -1) {
                bool can = true;
                for (int j = 0; j < 26; j++) {
                    if (cum[i][j] - cum[latest][j] == 0) {
                        continue;
                    }
                    if (cum[i][j] - cum[latest][j] < k) {
                        can = false;
                        break;
                    }
                }
                if (can) {
                    result = std::max(result, i - latest);
                }
            }
            else {
                result = std::max(result, i - latest);
            }
        }
        return result;
    }
};