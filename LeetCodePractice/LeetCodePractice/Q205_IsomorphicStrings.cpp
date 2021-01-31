#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
//5:46 to 6: 04
/**
Runtime: 4 ms, faster than 94.78% of C++ online submissions for Isomorphic Strings.
Memory Usage: 7.1 MB, less than 78.87% of C++ online submissions for Isomorphic Strings.
Next challenges:

*/

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
        {
            return false;
        }
        unordered_map<char, char> map;
        unordered_set<char> mapped;
        for (int i = 0; i < t.size(); i++)
        {
            if (map.find(s[i]) == map.cend())
            {
                if (mapped.find(t[i]) != mapped.cend())
                {
                    return false;
                }
                map[s[i]] = t[i];
                mapped.insert(t[i]);
            }
            else
            {
                if (map[s[i]] != t[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
};