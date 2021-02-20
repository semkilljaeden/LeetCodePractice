#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
//the most difficult DP in Leetcode
class Solution {
public:
    vector<vector<vector<int>>> memo;;
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        memo = vector<vector<vector<int>>>(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, -1)));
        return dp(boxes, 0, boxes.size(), 0);
    }

    int dp(vector<int>& s, int l, int r, int k) {
        if (r <= l) {
            return 0;
        }
        if (l + 1 == r) {
            return (1 + k) * (1 + k);
        }
        if (memo[l][r][k] != -1) {
            return memo[l][r][k];
        }
        int lb = l;
        while (s[lb] == s[l] && lb < r) {
            lb++;
        }
        int result = dp(s, lb, r, 0) + (k + lb - l) * (k + lb - l);

        for (int i = lb + 1; i < r; i++) {
            if (s[i] == s[l]) {
                result = std::max(result, dp(s, lb, i, 0) + dp(s, i, r, k + lb - l));
            }
        }
        return memo[l][r][k] = result;
    }
};



//9:46 10:07 brute force TLE

class Solution2 {
public:
    unordered_map<string, int> map;
    int removeBoxes(vector<int>& boxes) {
        string b;
        for (auto& x : boxes) {
            b += x + '0';
        }
        return dp(b);
    }

    int dp(string s) {
        if (s == "") {
            return 0;
        }
        if (map.count(s) > 0) {
            return map[s];
        }
        int score = 0;
        for (int i = 0; i < s.size(); i++) {
            int left = i;
            int right = i;
            while (left >= 0 && s[left] == s[i]) {
                left--;
            }
            while (right < s.size() && s[right] == s[i]) {
                right++;
            }
            int count = right - left - 1;
            string ls = left + 1 > 0 ? s.substr(0, left + 1) : "";
            string rs = right < s.size() ? s.substr(right, s.size() - 1) : "";
            score = max(score, count * count + dp(ls + rs));
        }
        return map[s] = score;
    }
};