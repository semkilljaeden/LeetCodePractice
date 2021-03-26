#include "LCHeader.h"
//1:58
class Robot {
public:
    // Returns true if the cell in front is open and robot moves into the cell.
    // Returns false if the cell in front is blocked and robot stays in the current cell.
    bool move();

    // Robot will stay in the same cell after calling turnLeft/turnRight.
    // Each turn will be 90 degrees.
    void turnLeft();
    void turnRight();

    // Clean the current cell.
    void clean();
};

 /**
  * // This is the robot's control interface.
  * // You should not implement it, or speculate about its implementation
  * class Robot {
  *   public:
  *     // Returns true if the cell in front is open and robot moves into the cell.
  *     // Returns false if the cell in front is blocked and robot stays in the current cell.
  *     bool move();
  *
  *     // Robot will stay in the same cell after calling turnLeft/turnRight.
  *     // Each turn will be 90 degrees.
  *     void turnLeft();
  *     void turnRight();
  *
  *     // Clean the current cell.
  *     void clean();
  * };
  */

class Solution {
public:
    vector<vector<int>> direction{ {-1, 0},
                                      {0, 1},
                                      {1,0},
                                      {0, -1} };
    void cleanRoom(Robot& robot) {
        unordered_set<string> visited;
        dfs(robot, 0, 0, visited, 0);
    }

    void back(Robot& r) {
        r.turnRight();
        r.turnRight();
        r.move();
        r.turnRight();
        r.turnRight();
    }

    void dfs(Robot& robot, int i, int j, unordered_set<string>& visited, int d) {
        auto sig = to_string(i) + "|" + to_string(j);
        visited.insert(sig);
        robot.clean();
        for (int idx = 0; idx < 4; idx++) {
            int nd = (idx + d) % 4;
            auto& x = direction[nd];
            int v = i + x[0];
            int h = j + x[1];
            if (visited.count(to_string(v) + "|" + to_string(h)) == 0 && robot.move()) {
                dfs(robot, v, h, visited, nd);
            }
            robot.turnRight();
        }
        back(robot);
    }

};