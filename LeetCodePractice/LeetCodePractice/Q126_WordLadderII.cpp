#include<vector>
#include<string>
#include<memory>
#include<unordered_set>
#include<unordered_map>
#include<utility>
#include<queue>
//8:11
/*
* BFS, damn c++ has much more strict time limit
*/
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_map<string, vector<string>> map;
        unordered_set<string> wl;
        for (auto it = wordList.cbegin(); it != wordList.cend(); it++)
        {
            if (*it == beginWord)
            {
                continue;
            }
            wl.insert(*it);
        }
        buildMap(wl, map);
        map[beginWord] = vector<string>();
        findAdjacent(wl, beginWord, map[beginWord]);
        queue<string> q;
        queue<vector<string>> q2;
        unordered_set<string> visited{ beginWord };
        q.push(beginWord);
        q2.push(vector<string> {beginWord});
        vector<vector<string>> result;
        int depth = 0;
        bool found = false;
        while (q.size() > 0 && !found)
        {
            int size = q.size();
            vector<string> tmp;
            while (size-- > 0)
            {
                auto w = q.front();
                q.pop();
                auto k = q2.front();
                q2.pop();
                if (map.find(w) == map.cend())
                {
                    continue;
                }
                for (auto& s : map[w])
                {
                    if (visited.count(s) > 0)
                    {
                        continue;
                    }
                    if (s == endWord)
                    {
                        found = true;
                        result.push_back(k);
                        result.back().push_back(s);
                    }
                    else
                    {
                        tmp.push_back(s);
                        q.push(s);
                        q2.push(k);
                        q2.back().push_back(s);
                    }
                }
            }
            visited.insert(tmp.begin(), tmp.end());
            depth++;
        }
        return result;
    }

    void buildMap(unordered_set<string>& wordList, unordered_map<string, vector<string>>& map)
    {
        for (auto iter1 = wordList.cbegin(); iter1 != wordList.cend(); iter1++)
        {
            map[*iter1] = vector<string>();
            findAdjacent(wordList, *iter1, map[*iter1]);
        }

    }

    void findAdjacent(unordered_set<string>& wl, string word, vector<string>& n)
    {
        for (size_t i = 0; i < word.size(); i++)
        {
            for (int j = 0; j < 27; j++)
            {
                if ('a' + j == word[i])
                {
                    continue;
                }
                char t = word[i];
                word[i] = 'a' + j;
                if (wl.count(word) > 0)
                {
                    n.push_back(word);
                }
                word[i] = t;
            }
        }
    }
};

