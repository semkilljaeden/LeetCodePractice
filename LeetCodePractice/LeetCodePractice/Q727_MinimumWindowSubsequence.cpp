#include "LCHeader.h"
//10:49 11:22 Hard, 33mins AC
class Solution {
public:
    string minWindow(string S, string T) {
        int s = S.size();
        int t = T.size();
        int tt = 0;
        vector<int> tp;
        for (int i = 0; i < s; i++) {
            if (tp.size() == t) {
                break;
            }
            if (S[i] == T[tt]) {
                tp.push_back(i);
                tt++;
            }
        }
        if (tp.size() < T.size()) {
            return "";
        }
        tp.push_back(S.size());
        int size = tp[tp.size() - 2] - tp[0] + 1;
        string result = S.substr(tp[0], size);
        bool unchanged = true;
        do {
            unchanged = true;
            for (int i = 0; i < tp.size() - 1; i++) {
                int pos = tp[i] + 1;
                while (pos < tp[i + 1]) {
                    if (S[pos] == T[i]) {
                        tp[i] = pos;
                        unchanged = false;
                        if (i == tp.size() - 2) {
                            break;
                        }
                    }
                    pos++;
                }
                if (!unchanged) {
                    break;
                }
            }
            int length = tp[tp.size() - 2] - tp[0] + 1;
            if (length < size) {
                size = length;
                result = S.substr(tp[0], size);

            }
        } while (!unchanged);
        return result;

    }
};