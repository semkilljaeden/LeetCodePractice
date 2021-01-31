#include<vector>
#include<string>
#include<memory>

using namespace std;

/*
* a potential memory leak version has much better performance
Runtime: 60 ms, faster than 90.05% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 48.4 MB, less than 25.80% of C++ online submissions for Implement Trie (Prefix Tree).
*/


class Trie3 {
public:
    /** Initialize your data structure here. */
    vector<Trie3*> trie;
    bool isLeaf;
    Trie3() : trie(26) {
        isLeaf = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.size() == 0)
        {
            return;
        }
        auto t = this;
        for (auto& c : word)
        {
            int x = c - 'a';
            if (t->trie[x] == nullptr)
            {
                t->trie[x] = new Trie3();
            }
            t = t->trie[x];
        }
        t->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.size() == 0)
        {
            return false;
        }
        auto t = this;
        for (auto& c : word)
        {
            int x = c - 'a';
            if (t->trie[x] == nullptr)
            {
                return false;
            }
            t = t->trie[x];
        }
        return t->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        if (word.size() == 0)
        {
            return false;
        }
        auto t = this;
        for (auto& c : word)
        {
            int x = c - 'a';
            if (t->trie[x] == nullptr)
            {
                return false;
            }
            t = t->trie[x];
        }
        return true;
    }

};



//8:31 to 9:33, too long for a medium
/*
Runtime: 88 ms, faster than 49.73% of C++ online submissions for Implement Trie (Prefix Tree).
Memory Usage: 50.1 MB, less than 13.26% of C++ online submissions for Implement Trie (Prefix Tree).
*/



class Trie {
public:
    /** Initialize your data structure here. */
    vector<unique_ptr<Trie>> trie;
    bool isLeaf;
    Trie() : trie(26) {
        isLeaf = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.size() == 0)
        {
            return;
        }
        Trie* t = this;
        for (auto& c : word)
        {
            int x = c - 'a';
            if (t->trie[x] == nullptr)
            {
                t->trie[x] = make_unique<Trie>();
            }
            t = t->trie[x].get();
        }
        t->isLeaf = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.size() == 0)
        {
            return false;
        }
        Trie* t = this;
        for (auto& c : word)
        {
            int x = c - 'a';
            if (t->trie[x] == nullptr)
            {
                return false;
            }
            t = t->trie[x].get();
        }
        return t->isLeaf;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string word) {
        if (word.size() == 0)
        {
            return false;
        }
        auto t = this;
        for (auto& c : word)
        {
            int x = c - 'a';
            if (t->trie[x] == nullptr)
            {
                return false;
            }
            t = t->trie[x].get();
        }
        return true;
    }
    
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

class Trie2{
public:
    /** Initialize your data structure here. */
    vector<unique_ptr<Trie2>> trie;
    bool isLeaf;
    Trie2() : trie(26) {
        isLeaf = false;
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        if (word.size() == 0)
        {
            return;
        }
        insert(0, word);
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        if (word.size() == 0)
        {
            return false;
        }
        return search(0, word);
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        if (prefix.size() == 0)
        {
            return false;
        }
        return startWith(0, prefix);
    }
private:
    void insert(int i, string& word)
    {
        if (i == word.size())
        {
            isLeaf = true;
            return;
        }
        if (trie[word[i] - 'a'] == nullptr)
        {
            trie[word[i] - 'a'] = make_unique<Trie2>();

        }
        trie[word[i] - 'a']->insert(i + 1, word);
        return;
    }

    bool search(int i, string& word) {
        if (i == word.size())
        {
            return isLeaf;
        }
        if (trie[word[i] - 'a'] != nullptr)
        {
            return trie[word[i] - 'a']->search(i + 1, word);
        }
        return false;
    }
    bool startWith(int i, string& word) {
        if (i == word.size())
        {
            return true;
        }
        if (trie[word[i] - 'a'] != nullptr)
        {
            return trie[word[i] - 'a']->startWith(i + 1, word);
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */