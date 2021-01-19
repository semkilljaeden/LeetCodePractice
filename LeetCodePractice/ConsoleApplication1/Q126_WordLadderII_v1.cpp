#include<vector>
#include<string>
#include<memory>
#include<unordered_set>
#include<unordered_map>
#include<utility>
#include<queue>
//8:11
/*
* DFS first attempt is too slow
*/
using namespace std;
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> v;
        auto result = findLaddersR(beginWord, endWord, wordList, v);
        vector<vector<string>> x;
        for (shared_ptr<vector<string>>& r : result)
        {
            reverse(r->begin(), r->end());
            x.push_back(*r);
        }
        return x;
    }

    vector<shared_ptr<vector<string>>> findLaddersR(string beginWord, string endWord, vector<string>& wordList, unordered_set<string>& visited) 
    {
        if (beginWord == endWord)
        {
            return vector<shared_ptr<vector<string>>>(1, shared_ptr<vector<string>>(new vector<string>(1, beginWord)));
        }
        else if (visited.size() == wordList.size())
        {
            return vector<shared_ptr<vector<string>>>();
        }
        vector<shared_ptr<vector<string>>> result;
        for (string& word : wordList)
        {
            if (isAdjacent(beginWord, word) && visited.count(word) == 0)
            {
                visited.insert(word);
                auto c = findLaddersR(word, endWord, wordList, visited);
                if (c.size() > 0 && (result.size() == 0 || result.size() > 0 && result[0]->size() == c[0]->size()))
                {
                    result.insert(result.end(), c.begin(), c.end());
                }
                else if (c.size() > 0 && result.size() > 0 && result[0]->size() > c[0]->size())
                {
                    result = c;
                }
                visited.erase(word);
            }
        }
        for (decltype(auto) v : result)
        {
            v->push_back(beginWord);
        }
        return result;
    }

    bool isAdjacent(const string& a, const string& b)
    {
        if (a == "1" || b == "1")
        {
            return false;
        }
        if (a.size() != b.size())
        {
            return false;
        }
        int count = 0;
        for (size_t i = 0; i < a.size(); i++)
        {
            if (a[i] != b[i])
            {
                count++;
            }
        }
        return count == 1;
    }
};