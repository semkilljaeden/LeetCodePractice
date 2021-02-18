#include<vector>
#include<string>
#include<memory>
#include<unordered_set>
#include<algorithm>
using namespace std;
//8:59 9:12 wtf, too easy????????????????????

class Solution {
public:
    static bool com(string& a, string& b) {
        return a.size() < b.size();
    }
    unordered_set<string> set;
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> result;
        sort(words.begin(), words.end(), com);
        for (auto& x : words) {
            if (x == "") {
                continue;
            }
            if (dp(x)) {
                result.push_back(x);
            }
            else {
                set.insert(x);
            }
        }
        return result;

    }

    bool dp(string& s, int pos = 0) {
        if (pos == s.size()) {
            return true;
        }
        for (int i = 1; pos + i <= s.size(); i++) {  //cannot inverse since the larger string has not yet in the set
            if (set.count(s.substr(pos, i)) > 0) {
                if (dp(s, i + pos)) {
                    return true;
                }
            }
        }
        return false;
    }
};


//6:54 weird bug, cannot find


class Solution {
public:
    static bool com(string& a, string& b) {
        return a.size() < b.size();
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if (words.size() == 0) {
            return vector<string>();
        }
        sort(words.begin(), words.end(), com);
        vector<string> result;
        Trie t;
        t.add(words[0]);
        for (auto& x : words) {
            if (x == "") {
                continue;
            }
            if (t.query(x, &t)) {
                result.push_back(x);
            }
            else {
                t.add(x);
            }
        }
        return result;
    }


    class Trie {
        vector<unique_ptr<Trie>> list;
        bool isWord;
    public:
        Trie() :list(26), isWord(false) {

        }

        void add(string& s, int pos = 0) {
            if (pos == s.size()) {
                isWord = true;
                return;
            }
            int idx = s[pos] - 'a';
            if (list[idx] == nullptr) {
                list[idx] = make_unique<Trie>();
            }
            list[idx]->add(s, pos + 1);
        }

        bool query(string& s, Trie* root, int pos = 0, bool isComp = false) {
            if (pos == s.size()) {
                return isComp && isWord;
            }
            int idx = s[pos] - 'a';
            if (isWord && root->query(s, root, pos, true)) {
                return true;
            }
            if (list[idx] == nullptr) {
                if (this == root) {
                    return false;
                }
                else {
                    return root->query(s, root, pos, true);
                }
            }
            else {
                return list[idx]->query(s, root, pos + 1, isComp);
            }
        }
    };
};