#include<string>
#include<vector>
using namespace std;
/*
Runtime: 12 ms, faster than 97.76% of C++ online submissions for Freedom Trail.
Memory Usage: 12.1 MB, less than 65.02% of C++ online submissions for Freedom Trail.
*/
class Solution {
public:
    vector<vector<int>> memo;
    int findRotateSteps(string ring, string key) {
        memo = vector<vector<int>>(ring.size() + 1, vector<int>(key.size() + 1, -1));
        int r = dp(ring, 0, key, 0);
        return r;
    }

    int dp(string& ring, int pos, string& key, int idx) {
        if (idx == key.size()) {
            return 0;
        }
        if (memo[pos][idx] != -1) {
            return memo[pos][idx];
        }
        int result = INT_MAX;
        for (int i = 0; i < ring.size(); i++) {
            int p = (pos + i) % ring.size();
            if (ring[p] == key[idx]) {
                result = std::min(result, 1 + i + dp(ring, p, key, idx + 1));
                break;
            }
        }
        for (int i = 0; i < ring.size(); i++) {
            int p = (pos - i + ring.size()) % ring.size();
            if (ring[p] == key[idx]) {
                result = std::min(result, 1 + i + dp(ring, p, key, idx + 1));
                break;
            }
        }
        return memo[pos][idx] = result;
    }
};


//2:11 3:11 no idea what is wrong, funny bug, local compiler works fine

class Solution {
public:
    int findRotateSteps(string ring, string key) {
        vector<vector<vector<int>>> memo(ring.size() + 1, vector<vector<int>>(key.size() + 1, vector<int>(2, -1)));
        return std::min(dp(ring, 0, key, 0, 1, memo), dp(ring, 0, key, 0, 0, memo));
    }

    int dp(string& ring, int pos, string& key, int idx, int direction, vector<vector<vector<int>>>& memo) {
        if (idx == key.size()) {
            return -1;
        }
        if (pos == ring.size()) {
            pos = 0;
        }
        if (pos == -1) {
            pos = ring.size() - 1;
        }
        if (memo[pos][idx][direction] != -1) {
            return memo[pos][idx][direction];
        }
        int result = 0;
        if (ring[pos] == key[idx]) {
            while (idx < key.size() && ring[pos] == key[idx]) {
                result += 1;
                idx++;
            }
            result += 1 + std::min(dp(ring, pos + 1, key, idx, 0, memo), dp(ring, pos - 1, key, idx, 1, memo));
        }
        else if (direction == 0) {
            result = 1 + dp(ring, pos + 1, key, idx, 0, memo);
        }
        else {
            result = 1 + dp(ring, pos - 1, key, idx, 1, memo);
        }
        return memo[pos][idx][direction] = result;
    }

    int main() {
        string s = "wfzhwppstxapizcqvgsgfjcmkcnjwoscawziwxjcyudtxtmceudbibykwaiixstjrtsxtaxxgacyydpjmpieclqjgssvpsmaisfe";
        string y = "ycicdxlcjypaasiagtsdawcuvqpcezkfpsjnstwvjztjsiiiedmxigfcqwuzywpxafjcbwgytbckspmgojiwsxhmsaxmsxtetxpr";
        int x = findRotateSteps(s, y);
        return 0;
   }
};