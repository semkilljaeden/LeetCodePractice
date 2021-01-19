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
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
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
        unordered_set<string> visited{ beginWord };
        q.push(beginWord);
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
                        return depth + 2;
                    }
                    else
                    {
                        tmp.push_back(s);
                        q.push(s);
                    }
                }
            }
            visited.insert(tmp.begin(), tmp.end());
            depth++;
        }
        return 0;
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

