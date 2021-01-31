#include<vector>
using namespace std;


/*
Runtime: 8 ms, faster than 68.98% of C++ online submissions for Best Time to Buy and Sell Stock IV.
Memory Usage: 12.7 MB, less than 21.66% of C++ online submissions for Best Time to Buy and Sell Stock IV.
*/
class Solution {
public:
    using pr = pair<int, int>;
    int count = 0;
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (k >= n / 2) {
            int res = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }
        vector<vector<pr>> memo(prices.size(), vector<pr>(k, make_pair(INT_MIN, INT_MIN)));
        int z = rec(k, 0, prices, memo, false);
        return z;
    }

    int rec(int k, int i, vector<int>& p, vector<vector<pr>>& memo, bool prev) {
        if (i > p.size() - 1 || k <= 0)
        {
            return 0;
        }
        int& m = prev ? memo[i][k - 1].first : memo[i][k - 1].second;
        if (m > INT_MIN)
        {
            return m;
        }
        int max = 0;
        if (prev)
        {
            max = std::max(max, rec(k, i + 1, p, memo, true));
            max = std::max(max, p[i] + rec(k - 1, i + 1, p, memo, false));
        }
        else
        {
            max = std::max(max, rec(k, i + 1, p, memo, false));
            max = std::max(max, -p[i] + rec(k, i + 1, p, memo, true));
        }
        m = max;
        return m;
    }
};

//O(nk) but can actually optimize out that for loop

class Solution3 {
public:
    using pr = pair<int, int>;
    int count = 0;
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        vector<vector<pr>> memo(prices.size(), vector<pr>(k, make_pair(INT_MIN, INT_MIN)));
        int z = rec(k, 0, prices, memo, false);
        return z;
    }

    int rec(int k, int i, vector<int>& p, vector<vector<pr>>& memo, bool prev) {
        int max = 0;
        if (i > p.size() - 1 || k <= 0)
        {
            return 0;
        }
        int& m = prev ? memo[i][k - 1].first : memo[i][k - 1].second;
        if (m > INT_MIN)
        {
            return m;
        }
        for (int y = 0; y <= k; y++)
        {
            int kk = k - y;
            if (prev)
            {
                max = std::max(max, rec(kk, i + 1, p, memo, true));
                max = std::max(max, p[i] + rec(kk - 1, i + 1, p, memo, false));
            }
            else
            {
                max = std::max(max, rec(kk, i + 1, p, memo, false));
                max = std::max(max, -p[i] + rec(kk, i + 1, p, memo, true));
            }
        }
        m = max;
        return m;
    }
};

//TLE again, o(n^2k) more optimized

class Solution2 {
public:
    using pr = pair<int, int>;
    int count = 0;
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        int n = prices.size();
        if (k >= n / 2) {
            int res = 0;
            for (int i = 1; i < n; ++i) {
                if (prices[i] > prices[i - 1]) res += prices[i] - prices[i - 1];
            }
            return res;
        }
        vector<vector<int>> memo(prices.size(), vector<int>(k, INT_MIN));
        int z = rec(k, 0, prices, memo);
        return z;
    }

    int rec(int k, int i, vector<int>& p, vector<vector<int>>& memo) {
        int rev = 0;
        int max = 0;
        if (i >= p.size() - 1 || k <= 0)
        {
            return 0;
        }
        if (memo[i][k - 1] > INT_MIN)
        {
            return memo[i][k - 1];
        }
        for (int x = i; x < p.size(); x++)
        {
            rev = p[x] - p[i];
            max = std::max(max, rev + rec(k - 1, x, p, memo));
            if (x != i)
            {
                max = std::max(max, rec(k, x, p, memo));
            }
        }
        return memo[i][k - 1] = max;
    }
};


//TLE again, o(n^2k)???? yes, even though only n times of the function being run, but each run take O(kn) so overall is O(n^2k)

class Solution5 {
public:
    using pr = pair<int, int>;
    int count = 0;
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() == 0)
        {
            return 0;
        }
        vector<vector<int>> memo(prices.size(), vector<int>(k, INT_MIN));
        int z = rec(k, 0, prices, memo);
        return z;
    }

    int rec(int k, int i, vector<int>& p, vector<vector<int>>& memo) {
        int rev = 0;
        int max = 0;
        if (i >= p.size() - 1 || k <= 0)
        {
            return 0;
        }
        if (memo[i][k - 1] > INT_MIN)
        {
            return memo[i][k - 1];
        }
        for (int y = 0; y <= k; y++)
        {
            for (int x = i; x < p.size(); x++)
            {
                rev = p[x] - p[i];
                int kk = k - y;
                if (kk == k && x == i)
                {
                    continue;
                }
                max = std::max(max, (kk < k ? rev : 0) + rec(kk, x, p, memo));
            }
        }
        count++;
        return memo[i][k - 1] = max;
    }
};
//9:05 to 10:22 1:08 to 1:17 TLE

class Solution8 {
public:
    using pr = pair<int, int>;
    int maxProfit(int k, vector<int>& prices) {
        if (prices.size() < 2 || k < 1)
        {
            return 0;
        }
        vector<pr> px;
        int buy = INT_MAX;
        int sell = INT_MAX;
        int rev = 0;
        int pos = 0;
        for (int& p : prices)
        {
            if (p < sell)
            {
                rev = sell - buy;
                if (rev > 0)
                {
                    px.push_back(make_pair(buy, sell));
                }
                buy = p;
                sell = p;
            }
            else if (p > buy && p > sell)
            {
                sell = p;
            }
        }
        rev = prices.back() - buy;
        rev = rev > 0 ? rev : 0;
        if (rev > 0)
        {
            px.push_back(make_pair(buy, prices.back()));
        }
        k = px.size() < k ? px.size() : k;
        vector<vector<vector<int>>> memo(px.size() + 1,
            vector<vector<int>>(px.size() + 1, vector<int>(k + 1, -1)));
        return cal(px, memo, 0, px.size(), k);
    }

    int cal(vector<pr>& p, vector<vector<vector<int>>>& memo, int i, int j, int k)
    {
        if (memo[i][j][k] > -1)
        {
            return memo[i][j][k];
        }
        if (k == 0 || i >= j || j - i < k)
        {
            memo[i][j][k] = 0;
            return 0;
        }
        int max = 0;
        if (k == 1)
        {
            for (int x = i; x < j; x++)
            {
                max = std::max(max, p[x].second - p[x].first);
            }
            int start = p[i].first;
            int end = p[i].second;
            for (int x = i + 1; x < j; x++)
            {
                if (p[x].first < end && p[x].first >= start && p[x].second >= end)
                {
                    end = p[x].second;
                }
                else
                {
                    max = std::max(max, end - start);
                    start = p[x].first;
                    end = p[x].second;
                }
            }
            max = std::max(max, end - start);
            memo[i][j][k] = max;
            return max;

        }

        for (int x = i + 1; x < j; x++)
        {
            for (int y = 0; y < k; y++)
            {
                max = std::max(cal(p, memo, i, x, y) + cal(p, memo, x, j, k - y), max);
            }
        }
        memo[i][j][k] = max;
        return max;
    }
};