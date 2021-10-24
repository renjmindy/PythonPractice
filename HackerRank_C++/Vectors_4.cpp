#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  int a = atoi((argv[1]));
  int b = atoi((argv[2]));
  int c = atoi((argv[3]));
  int d = atoi((argv[4]));
  int nums[3][3];
  
  //add code below this line
  for (int x = 0; x != 3; x++) {
    for (int y = 0; y != 3; y++) {
      if (x == 0) {
        if (y == 0) nums[x][y] = a;
        else if (y == 1) nums[x][y] = b;
        else nums[x][y] = a + b;
      } else if (x == 1) {
        if (y == 0) nums[x][y] = c;
        else if (y == 1) nums[x][y] = d;
        else nums[x][y] = c + d;
      } else {
        if (y == 0) nums[x][y] = a + c;
        else if (y == 1) nums[x][y] = b + d;
        else nums[x][y] = (a + b) + (c + d) + (a + c) + (b + d);
      }
    }
  }


  //add code above this line
  
  int row = sizeof(nums) / sizeof(nums[0]);
  int col = sizeof(nums[0]) / sizeof(int);
  
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (j == 2) {
        cout << nums[i][j] << endl;
      }
      else {
        cout << nums[i][j] << " ";
      }
    }
  }
  
  return 0;
  
}
