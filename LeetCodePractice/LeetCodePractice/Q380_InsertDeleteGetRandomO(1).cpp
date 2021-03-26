#include "LCHeader.h"
//2:18
class RandomizedSet {
public:
    /** Initialize your data structure here. */
    vector<int> v;
    unordered_map<int, int> index;
    int lastIndex = 0;
    RandomizedSet() {

    }

    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (index.count(val) > 0) {
            return false;
        }
        if (lastIndex < v.size()) {
            v[lastIndex] = val;
            index[val] = lastIndex;
            lastIndex++;
        }
        else {
            v.push_back(val);
            index[val] = v.size() - 1;
            lastIndex = v.size();
        }
        return true;
    }

    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (index.count(val) == 0) {
            return false;
        }
        int idx = index[val];
        index.erase(val);
        if (idx != lastIndex - 1) {
            index[v[lastIndex - 1]] = idx;
            swap(v[idx], v[lastIndex - 1]);
        }
        lastIndex--;
        return true;
    }

    /** Get a random element from the set. */
    int getRandom() {
        int r = rand() % (lastIndex - 0);
        return v[r];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */