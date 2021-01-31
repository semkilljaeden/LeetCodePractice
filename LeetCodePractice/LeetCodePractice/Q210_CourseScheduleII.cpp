#include<vector>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//11:14 to 12:21, took too long for a medium
/*
Runtime: 24 ms, faster than 85.70% of C++ online submissions for Course Schedule II.
Memory Usage: 16.1 MB, less than 16.01% of C++ online submissions for Course Schedule II.
Next challenges:
*/
class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        vector<int> result;
        unordered_set<int> visited;
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < n; i++)
        {
            map.insert({ i, vector<int>() });
        }
        for (auto& x : p)
        {
            map[x[0]].push_back(x[1]);
        }
        for (auto& x : map)
        {
            unordered_set<int> tmp_visited;
            if (x.second.size() == 0)
            {
                if (visited.count(x.first) == 0)
                {
                    result.push_back(x.first);
                    visited.insert(x.first);
                }
            }
            else if (visited.count(x.first) == 0)
            {
                if (!rec(x.first, result, visited, map, tmp_visited))
                {
                    return vector<int>();
                }
            }
        }
        return result;
    }

    bool rec(int start, vector<int>& result, unordered_set<int>& visited, unordered_map<int, vector<int>>& map, unordered_set<int>& tmp_visited)
    {
        if (tmp_visited.count(start) > 0 && visited.count(start) > 0)
        {
            return false;
        }
        if (visited.count(start) > 0)
        {
            return true;
        }
        bool k = true;
        visited.insert(start);
        tmp_visited.insert(start);
        for (auto& x : map[start])
        {
            k = k && rec(x, result, visited, map, tmp_visited);
        }
        if (!k)
        {
            return false;
        }
        result.push_back(start);
        tmp_visited.erase(start);
        return true;
    }
};