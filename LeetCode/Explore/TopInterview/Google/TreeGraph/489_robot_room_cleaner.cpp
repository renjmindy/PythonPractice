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
  
private:
  int dir_x[4] = {0, 1, 0, -1};
  int dir_y[4] = {1, 0, -1, 0};
  
  map<pair<int, int>, bool> visited;
  
  void backtrack(int x, int y, int d, Robot &robot) {
    visited[{x, y}] = true;
    robot.clean();
    
    for (int i = 0; i < 4; i++) {
      int new_d = (d + i) % 4;
      int new_x = x + dir_x[new_d];
      int new_y = y + dir_y[new_d];
      
      if (!visited[{new_x, new_y}] && robot.move()) {
        backtrack(new_x, new_y, new_d, robot);
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
      }
      robot.turnRight();
    }
  }
  
public:
    void cleanRoom(Robot& robot) {
      backtrack(0, 0, 0, robot);
    }
};
