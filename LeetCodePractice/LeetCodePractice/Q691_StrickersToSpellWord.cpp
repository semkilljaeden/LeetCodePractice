#include<vector>
#include<string>
#include<unordered_map>
#include<functional>
using namespace std;
//6:10 6:34
string h(const vector<int>& tar) {
    string s(tar.size(), '0');
    for (int i = 0; i < tar.size(); i++) {
        s[i] = tar[i] + '0';
    }
    return s;
}


class Solution {
public:
    unordered_map<string, int> map;
    int minStickers(vector<string>& stickers, string target) {
        vector<vector<int>> st;
        vector<int> tar = rearrange(target);
        for (auto& s : stickers) {
            st.push_back(rearrange(s));
        }
        long tmp = dp(st, tar);
        if (tmp > 1000000000) {
            return -1;
        }
        return tmp;
    }
    long dp(vector<vector<int>>& st, vector<int> tar) {
        string a = h(tar);
        if (map.find(a) != map.end()) {
            return map[a];
        }
        if (isEmpty(tar)) {
            return map[a] = 0;
        }
        long min = INT_MAX;
        for (int i = 0; i < st.size(); i++) {
            if (unchanged(tar, st[i])) {
                continue;
            }
            vector<int> r = minus(tar, st[i]);
            min = std::min(min, 1 + dp(st, r));
        }
        return map[a] = min;
    }

    static  inline bool isEmptyList(string mask) {
        for (auto& x : mask) {
            if (x != '1') {
                return false;
            }
        }
        return true;
    }


    static  inline vector<int> rearrange(string& s) {
        vector<int> result(26, 0);
        for (auto& c : s) {
            result[c - 'a']++;
        }
        return result;
    }

    static inline  bool unchanged(const vector<int>& l, const vector<int>& r) {
        bool unchanged = true;
        for (int i = 0; i < 26; i++) {
            if (l[i] == 0) {
                continue;
            }
            int tmp = l[i] - r[i];
            if (tmp != l[i]) {
                unchanged = false;
            }
        }
        return unchanged;
    }
    static inline  vector<int> minus(const vector<int>& l, const vector<int>& r) {
        vector<int> result(26, 0);
        for (int i = 0; i < 26; i++) {
            if (l[i] == 0) {
                continue;
            }
            int tmp = l[i] - r[i];
            tmp = tmp < 0 ? 0 : tmp;
            result[i] = tmp;
        }
        return result;
    }

    static inline bool isEmpty(vector<int>& l) {
        bool zero = true;
        bool unchanged = true;
        for (int i = 0; i < 26; i++) {
            if (l[i] != 0) {
                return false;
            }
        }
        return true;
    }

    static  inline int plus(vector<int>& l, const vector<int>& r) {
        for (int i = 0; i < 26; i++) {
            l[i] += r[i];
        }
        return 0;
    }
};



class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        int m = stickers.size();
        vector<vector<int>> mp(m, vector<int>(26, 0));
        unordered_map<string, int> dp;
        // count characters a-z for each sticker 
        for (int i = 0; i < m; i++)
            for (char c : stickers[i]) mp[i][c - 'a']++;
        dp[""] = 0;
        return helper(dp, mp, target);
    }
private:
    int helper(unordered_map<string, int>& dp, vector<vector<int>>& mp, string target) {
        if (dp.count(target)) return dp[target];
        int ans = INT_MAX, n = mp.size();
        vector<int> tar(26, 0);
        for (char c : target) tar[c - 'a']++;
        // try every sticker
        for (int i = 0; i < n; i++) {
            // optimization
            if (mp[i][target[0] - 'a'] == 0) continue;
            string s;
            // apply a sticker on every character a-z
            for (int j = 0; j < 26; j++)
                if (tar[j] - mp[i][j] > 0) s += string(tar[j] - mp[i][j], 'a' + j);
            int tmp = helper(dp, mp, s);
            if (tmp != -1) ans = min(ans, 1 + tmp);
        }
        dp[target] = ans == INT_MAX ? -1 : ans;
        return dp[target];
    }
};