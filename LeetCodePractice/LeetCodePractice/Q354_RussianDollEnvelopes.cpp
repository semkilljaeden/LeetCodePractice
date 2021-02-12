#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
//10:53 read the answer 11:02

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        if (e.size() == 0 || e[0].size() == 0) {
            return 0;
        }
        sort(e.begin(), e.end(), [](vector<int>& i, vector<int>& j) {return i[0] < j[0] || i[0] == j[0] && i[1] < j[1]; });
        vector<int> memo(e.size());
        memo[0] = 1;
        int result = 1;
        for (int i = 1; i < e.size(); i++) {
            int max = 1;
            for (int j = 0; j < i; j++) {
                auto& x = e[i];
                auto& p = e[j];
                if (x[0] > p[0] && x[1] > p[1]) {
                    max = std::max(max, memo[j] + 1);
                }
            }
            result = std::max(result, memo[i] = max);
        }
        return result;
    }
};


//9:19 rested, LTE

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        using h = std::hash<string>;
        auto hash = [](const vector<int>& n) {return h()(to_string(n[0]) + to_string(n[1])); };
        auto equal = [hash](const vector<int>& l, const vector<int>& r) {return hash(l) == hash(r); };
        unordered_map<vector<int>, int, [] size_t (const vector<int>& n)->size_t, decltype(equal)> memo(7, hash, equal);
        using k = decltype(hash);
        vector<int> x{ 0, 0 };
        return m(envelopes, x, memo) - 1;
    }

    int m(vector<vector<int>>& e, vector<int>& p, unordered_map<vector<int>, int, []size_t (const vector<int>& n), [hash](const vector<int>& l, const vector<int>& r)>& memo) {
        int max = 0;
        if (memo.find(p) != memo.end()) {
            return memo[p];
        }
        for (auto& x : e) {
            if (x[0] > p[0] && x[1] > p[1]) {
                max = std::max(max, m(e, x, memo));
            }
        }
        return memo[p] = max + 1;
    }
};