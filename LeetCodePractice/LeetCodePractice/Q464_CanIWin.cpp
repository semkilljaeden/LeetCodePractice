#include<vector>
#include<unordered_map>
using namespace std;

//4:25 7:33 fucking silly bug
class Solution {
public:
    using mm = vector<vector<unordered_map<int, bool>>>;
    bool canIWin(int m, int d) {
        if (d <= m) {
            return true;
        }
        if (((1 + m) / 2 * m) < d) {
            return false;
        }
        int t = m;
        t = static_cast<int>(pow(2, m)) - 1;
        mm memo(2, vector<unordered_map<int, bool>>(d + 1, unordered_map<int, bool>()));
        return dp(t, d, 0, memo);
    }

    bool dp(int bitmap, int total, int count, mm& memo) {
        if (total <= 0) {
            return count % 2 == 1;
        }
        if (memo[count % 2][total].find(bitmap) != memo[count % 2][total].end()) {
            return memo[count % 2][total][bitmap];
        }
        vector<int> r = parse(bitmap);
        bool result = true;
        if (count % 2 == 1) {
            result = true;
            for (auto& z : r) {
                int v = static_cast<int>(pow(2, z - 1));
                result &= dp(bitmap - v, total - z, count + 1, memo);
            }
        }
        else {
            result = false;
            for (auto& z : r) {
                int v = static_cast<int>(pow(2, z - 1));
                if (dp(bitmap - v, total - z, count + 1, memo)) {
                    result = true;
                    break;
                }
            }
        }
        return memo[count % 2][total][bitmap] = result;
    }



    vector<int> parse(int bitmap) {
        vector<int> result;
        while (bitmap > 0) {
            int tmp = (bitmap - 1) & bitmap;
            result.push_back(static_cast<int>(log2((bitmap - tmp))) + 1);
            bitmap = tmp;
        }
        return result;
    }
};