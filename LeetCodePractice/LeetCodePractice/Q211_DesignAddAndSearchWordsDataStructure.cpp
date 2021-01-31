#include<vector>
#include<string>
#include<memory>
using namespace std;
//12:42 to 12:56 medium, trie, did before
/*
Runtime: 80 ms, faster than 89.49% of C++ online submissions for Design Add and Search Words Data Structure.
Memory Usage: 46.6 MB, less than 35.68% of C++ online submissions for Design Add and Search Words Data Structure.
*/
class WordDictionary {
public:
    class Trie {

        vector<unique_ptr<Trie>> tries;
        bool isLeaf;
    public:
        Trie() : tries(26), isLeaf(false)
        {

        }
        void addWord(string& word, int pos) {
            if (pos == word.size())
            {
                isLeaf = true;
                return;
            }
            if (tries[word[pos] - 'a'] == nullptr)
            {
                tries[word[pos] - 'a'] = make_unique<Trie>();
            }
            tries[word[pos] - 'a']->addWord(word, pos + 1);
            return;
        }

        bool search(string& word, int pos) {
            if (pos == word.size())
            {
                return isLeaf;
            }
            bool find = false;
            if (word[pos] != '.')
            {
                if (tries[word[pos] - 'a'] != nullptr)
                {
                    return tries[word[pos] - 'a']->search(word, pos + 1);
                }
                else
                {
                    return false;
                }
            }
            else
            {
                for (auto& x : tries)
                {
                    if (x == nullptr)
                    {
                        continue;
                    }
                    find = find | x->search(word, pos + 1);
                }
            }
            return find;
        }

    };
    /** Initialize your data structure here. */
    unique_ptr<Trie> trie;
    WordDictionary() {
        trie = make_unique<Trie>();
    }

    void addWord(string word) {
        if (word.size() == 0)
        {
            return;
        }
        trie->addWord(word, 0);
        return;
    }

    bool search(string word) {
        if (word.size() == 0)
        {
            return false;
        }
        return trie->search(word, 0);

    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */