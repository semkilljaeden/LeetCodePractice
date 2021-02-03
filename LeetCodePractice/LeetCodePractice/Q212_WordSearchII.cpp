#include<vector>
#include<string>
#include<memory>
#include<unordered_set>
using namespace std;


//7:54 8: 44 TLE
/*
Runtime: 152 ms, faster than 53.71% of C++ online submissions for Word Search II.
Memory Usage: 9.2 MB, less than 17.25% of C++ online submissions for Word Search II.
*/

class Solution {
public:
    class Trie
    {
    private:
        vector<unique_ptr<Trie>> tries;
        bool _isLeaf;
        unique_ptr<string> word;
        void add(string& word, int i)
        {
            if (i == word.size())
            {
                _isLeaf = true;
                this->word = make_unique<string>(word);
                return;
            }
            auto& x = tries[word[i] - 'a'];
            if (x == nullptr)
            {
                x = make_unique<Trie>();
            }
            x->add(word, i + 1);
            return;
        }
    public:
        Trie() :tries(26), _isLeaf(false)
        {

        }
        unique_ptr<string> getWord()
        {
            if (word != nullptr)
            {
                return move(word);
            }
            return nullptr;
        }
        bool isLeaf()
        {
            return _isLeaf;
        }
        void add(string& word)
        {
            add(word, 0);
        }
        Trie* match(char c)
        {
            return tries[c - 'a'].get();
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0 || board.size() == 0 || board[0].size() == 0)
        {
            return vector<string>();
        }
        Trie t;
        for (auto& x : words)
        {
            t.add(x);
        }
        vector<int> visited(board.size() * board[0].size());
        vector<string> result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (result.size() == words.size())
                {
                    return result;
                }
                rec(board, i, j, visited, &t, result);
            }
        }
        return result;

    }

    void rec(vector<vector<char>>& board, int i, int j, vector<int>& visited, Trie* t, vector<string>& result)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i * board[0].size() + j] == 1)
        {
            if (t->isLeaf())
            {
                auto x = t->getWord();
                if (x != nullptr)
                {
                    result.emplace_back(move(*x));
                }
            }
            return;
        }
        auto x = t->match(board[i][j]);
        if (x == nullptr)
        {
            return;;
        }
        visited[i * board[0].size() + j] = 1;
        rec(board, i + 1, j, visited, x, result);
        rec(board, i - 1, j, visited, x, result);
        rec(board, i, j + 1, visited, x, result);
        rec(board, i, j - 1, visited, x, result);
        visited[i * board[0].size() + j] = 0;
        return;
    }
};
/*
Runtime: 580 ms, faster than 29.26% of C++ online submissions for Word Search II.
Memory Usage: 9.1 MB, less than 33.47% of C++ online submissions for Word Search II.
*/
class Solution1 {
public:
    class Trie
    {
    private:
        vector<unique_ptr<Trie>> tries;
        bool _isLeaf;
        string word;
        void add(string& word, int i)
        {
            if (i == word.size())
            {
                _isLeaf = true;
                this->word = word;
                return;
            }
            auto& x = tries[word[i] - 'a'];
            if (x == nullptr)
            {
                x = make_unique<Trie>();
            }
            x->add(word, i + 1);
            return;
        }
    public:
        Trie() :tries(26), _isLeaf(false)
        {

        }
        string getWord()
        {
            return word;
        }
        bool isLeaf()
        {
            return _isLeaf;
        }
        void add(string& word)
        {
            add(word, 0);
        }
        Trie* match(char c)
        {
            return tries[c - 'a'].get();
        }
    };
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if (words.size() == 0 || board.size() == 0 || board[0].size() == 0)
        {
            return vector<string>();
        }
        Trie t;
        for (auto& x : words)
        {
            t.add(x);
        }
        vector<int> visited(board.size() * board[0].size());
        unordered_set<string> tmp_result;
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                rec(board, i, j, visited, &t, tmp_result);
            }
        }
        vector<string> result(tmp_result.cbegin(), tmp_result.cend());
        return result;

    }

    void rec(vector<vector<char>>& board, int i, int j, vector<int>& visited, Trie* t, unordered_set<string>& result)
    {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || visited[i * board[0].size() + j] == 1)
        {
            if (t->isLeaf())
            {
                result.emplace(t->getWord());
            }
            return;
        }
        auto x = t->match(board[i][j]);
        if (x == nullptr)
        {
            return;;
        }
        visited[i * board[0].size() + j] = 1;
        rec(board, i + 1, j, visited, x, result);
        rec(board, i - 1, j, visited, x, result);
        rec(board, i, j + 1, visited, x, result);
        rec(board, i, j - 1, visited, x, result);
        visited[i * board[0].size() + j] = 0;
        return;
    }
};