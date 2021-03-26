#include "LCHeader.h"
//10:17

class MagicDictionary {
public:
    /** Initialize your data structure here. */
    unordered_map<string, vector<string>> set;
    MagicDictionary() {

    }

    void buildDict(vector<string> dictionary) {
        for (auto& x : dictionary) {
            for (int i = 0; i < x.size(); i++) {
                string s = x;
                s[i] = '*';
                set[s].push_back(x);
            }
        }
    }

    bool search(string searchWord) {
        auto tmp = searchWord;
        for (int i = 0; i < searchWord.size(); i++) {
            auto t = searchWord[i];
            tmp[i] = '*';
            if (set.count(tmp) > 0 && (set[tmp].size() > 1 || set[tmp][0].compare(searchWord)) != 0) {
                return true;
            }
            tmp[i] = t;
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */