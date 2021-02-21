#include<vector>
#include<string>
#include<unordered_map>
using namespace std;
//weird memo bug
class Solution {
public:
    vector<int> price;
    vector<vector<int>> special;

    unordered_map<string, long> memo;

    string vts(const vector<int>& s) const {
        string v;
        for (auto& x : s) {
            v += to_string(x);
        }
        return v;
    }
    int N;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        this->price = price;
        this->special = special;
        this->N = needs.size();
        return dp(needs);
    }

    long dp(vector<int>& need) {
        bool isZero = true;
        for (auto& x : need) {
            if (x != 0) {
                isZero = false;
            }
            if (x < 0) {
                return INT_MAX;
            }
        }
        if (isZero) {
            return 0;
        }
        if (memo.find(vts(need)) != memo.end()) {
            return memo[vts(need)];
        }
        long result = INT_MAX;
        for (int i = 0; i < N; i++) {
            need[i]--;
            result = std::min(result, price[i] + dp(need));
            need[i]++;
        }
        for (int i = 0; i < special.size(); i++) {
            long tmp = 0;
            for (int j = 0; j < N; j++) {
                need[j] -= special[i][j];
            }
            result = std::min(result, special[i].back() + dp(need));
            for (int j = 0; j < N; j++) {
                need[j] += special[i][j];
            }
        }
        return memo[vts(need)] = result;
    }
};

//4:44 5:00 T:E recursion
class Solution2 {
public:
    vector<int> price;
    vector<vector<int>> special;
    int N;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        this->price = price;
        this->special = special;
        this->N = needs.size();
        return dp(needs);
    }

    long dp(vector<int> need) {
        bool isZero = true;
        for (auto& x : need) {
            if (x != 0) {
                isZero = false;
            }
            if (x < 0) {
                return INT_MAX;
            }
        }
        if (isZero) {
            return 0;
        }
        long result = INT_MAX;
        for (int i = 0; i < N; i++) {
            need[i]--;
            result = std::min(result, price[i] + dp(need));
            need[i]++;
        }
        for (int i = 0; i < special.size(); i++) {
            long tmp = 0;
            for (int j = 0; j < N; j++) {
                need[j] -= special[i][j];
            }
            result = std::min(result, special[i].back() + dp(need));
            for (int j = 0; j < N; j++) {
                need[j] += special[i][j];
            }
        }
        return result;
    }
};