#include "LCHeader.h"
#include <queue>

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(2, 1)));
        vector<vector<vector<int>>> ind(n, vector<vector<int>>(n, vector<int>(2, 0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 2 && j == 1) {
                    int daasd = 0;
                }
                ind[i][j][0] = graph[j].size();
                for (auto& x : graph[j]) {
                    if (x == 0) {
                        ind[i][j][0]--;
                    }
                }
                ind[i][j][1] = graph[i].size();
                for (auto& x : graph[i]) {
                    if (x == 0) {
                        ind[i][j][1]--;
                    }
                }
            }
        }
        queue<vector<int>> q;
        for (int i = 0; i < n; i++) {
            dp[i][0][0] = 0;
            dp[i][0][1] = 0;
            q.push({ i, 0, 0, 0 });
            q.push({ i, 0, 1, 0 });
            if (i == 0) {
                continue;
            }
            dp[i][i][0] = 2;
            dp[i][i][1] = 2;
            q.push({ i, i, 0, 2 });
            q.push({ i, i, 1, 2 });
        }
        while (q.size() > 0) {
            auto node = q.front();
            q.pop();
            int& turn = node[2];
            int& cat = node[0];
            int& mouse = node[1];
            int& color = node[3];
            for (auto& x : graph[turn % 2 == 1 ? mouse : cat]) {
                auto tmp = vector<int>(4, 0);
                int& p_turn = tmp[2] = (turn + 1) % 2;
                int& p_mouse = tmp[1] = turn % 2 == 1 ? x : mouse;
                int& p_cat = tmp[0] = turn % 2 == 0 ? x : cat;
                if (p_cat == 2 && p_mouse == 1 && p_turn == 0) {
                    int ggg = 0;
                }
                if (p_cat == 0) {
                    continue;
                }
                if (dp[p_cat][p_mouse][p_turn] != 1) {
                    continue;
                }
                if (p_turn == 1) {
                    if (color == 2) {
                        dp[p_cat][p_mouse][p_turn] = 2;
                        tmp[3] = 2;
                        q.push(tmp);
                    }
                    else {
                        ind[p_cat][p_mouse][p_turn]--;
                        if (ind[p_cat][p_mouse][p_turn] == 0) {
                            dp[p_cat][p_mouse][p_turn] = 0;
                            tmp[3] = 0;
                            q.push(tmp);
                        }
                    }
                }
                else {
                    if (color == 0) {
                        dp[p_cat][p_mouse][p_turn] = 0;
                        tmp[3] = 0;
                        q.push(tmp);
                    }
                    else {
                        ind[p_cat][p_mouse][p_turn]--;
                        if (ind[p_cat][p_mouse][p_turn] == 0) {
                            dp[p_cat][p_mouse][p_turn] = 2;
                            tmp[3] = 2;
                            q.push(tmp);
                        }
                    }
                }
            }
        }
        int r = dp[2][1][0];
        if (r == 0) {
            r = 1;
        }
        else if (r == 1) {
            r = 0;
        }
        return r;
    }
};






//use 2n as the end criteria of the cycle

class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<vector<int>>> dp(2 * n + 1, vector<vector<int>>(n, vector<int>(n, -1)));
        int x = go(graph, 2, 1, 0, dp);
        if (x == 1) {
            x = 0;
        }
        else if (x == 0) {
            x = 1;
        }
        return x;
    }

    int go(vector<vector<int>>& graph, int cat, int mouse, int turn, vector<vector<vector<int>>>& dp) {
        if (mouse == 0) {
            return 0;
        }
        if (cat == mouse) {
            return 2;
        }
        if (dp[turn][mouse][cat] != -1) {
            return dp[turn][mouse][cat];
        }
        int r = 0;
        if (turn == graph.size() * 2) {
            return 1;
        }
        if (turn % 2 == 0) {
            r = INT_MAX;
            for (int i = 0; i < graph[mouse].size(); i++) {
                auto& x = graph[mouse][i];
                int score = go(graph, cat, x, turn + 1, dp);
                r = std::min(r, score);
            }
            int x = r;
        }
        else {
            r = INT_MIN;
            for (int i = 0; i < graph[cat].size(); i++) {
                auto& x = graph[cat][i];
                if (x == 0) {
                    continue;
                }
                int score = go(graph, x, mouse, turn + 1, dp);
                r = std::max(r, score);
            }
            int x = r;
        }
        return dp[turn][mouse][cat] = r;
    }
};



//2:09 does not work because of the cycle
class Solution {
public:
    int catMouseGame(vector<vector<int>>& graph) {
        unordered_set<string> visited;
        vector<string> v;
        return go(graph, 2, 1, 0, visited, v);
    }

    int go(vector<vector<int>>& graph, int cat, int mouse, int turn, unordered_set<string>& visited, vector<string>& v) {
        if (mouse == 0) {
            return 0;
        }
        if (cat == mouse) {
            return 2;
        }
        string sig = to_string(mouse) + "|" + to_string(cat) + "|" + to_string(turn % 2);
        if (visited.count(sig) > 0) {
            return 1;
        }
        visited.insert(sig);
        v.push_back(sig);
        int r = 0;
        if (turn % 2 == 0) {
            r = INT_MAX;
            for (int i = 0; i < graph[mouse].size(); i++) {
                auto& x = graph[mouse][i];
                int score = go(graph, cat, x, turn + 1, visited, v);
                if (mouse == 5 && cat == 3 && turn == 8) {
                    int j = 1;
                }
                r = std::min(r, score);
            }
            int x = r;
        }
        else {
            r = INT_MIN;
            for (int i = 0; i < graph[cat].size(); i++) {
                auto& x = graph[cat][i];
                if (x == 0) {
                    continue;
                }
                int score = go(graph, x, mouse, turn + 1, visited, v);
                if (mouse == 5) {
                    int j = 1;
                }
                r = std::max(r, score);
            }
            int x = r;
        }
        visited.erase(sig);
        v.pop_back();
        return r;
    }
};