#include "LCHeader.h"

/*
Runtime: 1864 ms, faster than 5.20% of C++ online submissions for Smallest Sufficient Team.
Memory Usage: 634.4 MB, less than 5.20% of C++ online submissions for Smallest Sufficient Team.
*/



//4:11 4:53 AC

class Solution {
public:
    int full;
    vector<int> max;
    vector<int> min;
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        max = vector<int>{ 100000 };
        min = vector<int>{ 0 };
        unordered_map<string, int> encoder;
        int code = 0;
        for (auto& x : req_skills) {
            encoder[x] = code++;
        }
        vector<int> coded_people(people.size(), 0);
        for (int i = 0; i < people.size(); i++) {
            int base = 0;
            for (auto& y : people[i]) {
                base |= (1 << encoder[y]);
            }
            coded_people[i] = base;
        }
        full = (1 << encoder.size()) - 1;
        vector<vector<vector<int>>> memo(coded_people.size() + 1, vector<vector<int>>(1 << req_skills.size(), vector<int>(2, -1)));
        auto min = dp(coded_people, 0, 0, memo);
        vector<int> result(min.cbegin() + 1, min.cend());
        return result;
    }

    vector<int>& dp(vector<int>& coded_people, int idx, int skills, vector<vector<vector<int>>>& memo) {
        if (memo[idx][skills][0] != -1) {
            return memo[idx][skills];
        }
        if (skills == full) {
            return memo[idx][skills] = min;
        }
        if (idx == coded_people.size()) {
            return memo[idx][skills] = max;
        }
        auto& left = dp(coded_people, idx + 1, skills, memo);
        auto& right = max;
        if (coded_people[idx] > 0) {
            right = dp(coded_people, idx + 1, skills | coded_people[idx], memo);
        }
        if (left[0] < right[0] + 1) {
            memo[idx][skills] = left;
        }
        else {
            right[0]++;
            right.push_back(idx);
            memo[idx][skills] = right;
        }
        return memo[idx][skills];
    }
};