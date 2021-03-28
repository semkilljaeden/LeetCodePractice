#include "LCHeader.h"
//improved version//2:53 3:17


class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) {
            auto tmp = words[i];
            reverse(tmp.begin(), tmp.end());
            map[tmp] = i;
        }
        vector<vector<int>> result;
        for (int j = 0; j < words.size(); j++) {
            auto& x = words[j];
            if (x == "") {
                continue;
            }
            for (int i = 0; i < x.size() - 1; i++) {
                auto tmp = x.substr(i + 1, x.size() - i - 1);
                if (isPal(x, 0, i) && map.count(tmp) > 0) {
                    result.push_back({ map[tmp], j });
                }
            }
            for (int i = 1; i < x.size(); i++) {
                auto tmp = x.substr(0, i);
                if (isPal(x, i, x.size() - 1) && map.count(tmp) > 0) {
                    result.push_back({ j, map[tmp] });
                }
            }
            if (isPal(x, 0, x.size() - 1) && map.count("") > 0) {
                result.push_back({ j, map[""] });
                result.push_back({ map[""], j });
            }
            auto tmp = x;
            reverse(tmp.begin(), tmp.end());
            if (tmp != x && map.count(x) > 0) {
                result.push_back({ j, map[x] });
            }
        }
        return result;
    }



    inline bool isPal(const string& s, int i, int j) {
        if (s.size() == 0) {
            return false;
        }
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};




//10:18 10:55 TLE not TLE good solution but with bug
//11:43 fucking stupid bug. 
/*
Runtime: 92 ms, faster than 99.15% of C++ online submissions for Palindrome Pairs.
Memory Usage: 36.7 MB, less than 91.98% of C++ online submissions for Palindrome Pairs.

*/
class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        unordered_map<string, int> map;
        for (int i = 0; i < words.size(); i++) {
            auto x = words[i];
            reverse(x.begin(), x.end());
            map[x] = i;
        }
        vector<vector<int>> result;
        for (int x = 0; x < words.size(); x++) {
            auto& word = words[x];
            if (map.count(word) > 0 && map[word] != x) {
                result.push_back(vector<int>{x, map[word]});
            }
            for (int i = 0; i < word.size() / 2; i++) {
                int left = i - 1;
                if (i + 1 < word.size() && word[i + 1] == word[i]) {
                    int right = i + 2;
                    compare(word, left, right);
                    if (left == -1 && right < word.size()) {
                        string tmp = word.substr(right, word.size() - right);
                        if (map.count(tmp) > 0 && map[tmp] != x) {
                            result.push_back(vector<int>{map[tmp], x});
                        }
                    }
                }
                left = i - 1;
                int right = i + 1;
                compare(word, left, right);
                if (left == -1 && right < word.size()) {
                    string tmp = word.substr(right, word.size() - right);
                    if (map.count(tmp) > 0 && map[tmp] != x) {
                        result.push_back(vector<int>{map[tmp], x});
                    }
                }
            }

            for (int i = word.size() - 1; i >= (int)word.size() / 2; i--) {
                int right = i + 1;
                if (i - 1 >= 0 && word[i - 1] == word[i]) {
                    int left = i - 2;
                    compare(word, left, right);
                    if (right == word.size() && left >= 0) {
                        string tmp = word.substr(0, left + 1);
                        if (map.count(tmp) > 0 && map[tmp] != x) {
                            result.push_back(vector<int>{x, map[tmp]});
                        }
                    }
                }
                right = i + 1;
                int left = i - 1;
                compare(word, left, right);
                if (right == word.size() && left >= 0) {
                    string tmp = word.substr(0, left + 1);
                    if (map.count(tmp) > 0 && map[tmp] != x) {
                        result.push_back(vector<int>{x, map[tmp]});
                    }
                }
            }
            int left = word.size() / 2 - 1;
            int right = word.size() / 2 + 1;
            if (word.size() % 2 == 0 && ((int)word.size() / 2 - 1) >= 0 && word[word.size() / 2 - 1] == word[word.size() / 2]) {
                left = word.size() / 2 - 2;
                right = word.size() / 2 + 1;
            }
            compare(word, left, right);
            if (right == word.size() && left == -1) {
                if (map.count("") > 0 && map[""] != x) {
                    result.push_back(vector<int>{x, map[""]});
                    result.push_back(vector<int>{map[""], x});
                }
            }
        }
        return result;
    }

    void compare(string& word, int& left, int& right) {
        while (left >= 0 && right < word.size() && word[left] == word[right]) {
            left--;
            right++;
        }
    }
};