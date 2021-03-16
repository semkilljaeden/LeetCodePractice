#include "LCHeader.h"
//9:34 9:45
/*
Runtime: 296 ms, faster than 78.97% of C++ online submissions for Time Based Key-Value Store.
Memory Usage: 130.5 MB, less than 48.41% of C++ online submissions for Time Based Key-Value Store.
*/
class TimeMap {
public:
    /** Initialize your data structure here. */
    unordered_map<string, map<int, string>> map;
    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        map[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        if (map.count(key) == 0) {
            return "";
        }
        auto itr = map[key].lower_bound(timestamp);
        if (itr == map[key].end()) {
            return prev(itr)->second;
        }
        else if (itr->first == timestamp) {
            return itr->second;
        }
        else if (itr == map[key].begin()) {
            return "";
        }
        else {
            return prev(itr)->second;
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */