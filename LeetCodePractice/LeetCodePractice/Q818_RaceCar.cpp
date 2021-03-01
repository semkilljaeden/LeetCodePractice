#include "LCHeader.h"
#include<queue>
//3:51 4:08halt 4:12 6:49 read the answer

class Solution {
public:
    int racecar(int target) {
        unordered_set<string> visited;
        queue<pair<int, int>> q;
        q.push(make_pair(0, 1));
        int count = 0;
        while (q.size() > 0) {
            int size = q.size();
            while (size > 0) {
                auto p = q.front();
                q.pop();
                if (p.first == target) {
                    return count;
                }
                string sig = to_string(p.first) + " " + to_string(p.second);
                if (visited.count(sig) > 0 || p.first < -10000 || p.first > target + 10000) {
                    size--;
                    continue;
                }
                visited.insert(sig);
                int pos = p.first;
                int speed = p.second;
                q.push(make_pair(pos + speed, speed * 2));
                q.push(make_pair(pos, speed > 0 ? -1 : 1));
                size--;
            }
            count++;
        }
        return 0;
    }

};