#include<vector>
#include<unordered_map>
using namespace std;
//11:37itr 11:58 what a fucking idiot am i for an easy question
class TwoSum {
public:
    /** Initialize your data structure here. */
    unordered_map<long, long> map;
    TwoSum() {

    }

    /** Add the number to an internal data structure.. */
    void add(int number) {
        map[number]++;
    }

    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        long b;
        for (const auto& p : map)
        {
            b = value - p.first;
            if (map.find(b) != map.end() && (b != p.first || b == p.first && p.second > 1))
            {
                return true;
            }
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */