#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

//add class definitions below this line

class Median {
  public:
  
    double CalculateMedian(double n1, double n2, double n3, double n4, double n5) {
      nums.clear();
      nums.push_back(n1);
      nums.push_back(n2);
      nums.push_back(n3);
      nums.push_back(n4);
      nums.push_back(n5);
      sort(nums.begin(), nums.end());
      return nums[2];
    }
  
    double CalculateMedian(double n1, double n2, double n3, double n4) {
      nums.clear();
      nums.push_back(n1);
      nums.push_back(n2);
      nums.push_back(n3);
      nums.push_back(n4);
      sort(nums.begin(), nums.end());
      return (nums[1] + nums[2]) / 2;
    }
  
    double CalculateMedian(double n1, double n2, double n3) {
      nums.clear();
      nums.push_back(n1);
      nums.push_back(n2);
      nums.push_back(n3);
      sort(nums.begin(), nums.end());
      return nums[1];
    }
  
    double CalculateMedian(double n1, double n2) {
      return (n1 + n2) / 2;
    }
  
  private:
    vector<double> nums;
};

//add class definitions above this line


int main() {
  
  //DO NOT EDIT code below this line
   
  Median m;
  cout << m.CalculateMedian(3, 5, 1, 4, 2) << endl;
  cout << m.CalculateMedian(8, 6, 4, 2) << endl;
  cout << m.CalculateMedian(9, 3, 7) << endl;
  cout << m.CalculateMedian(5, 2) << endl;
  Median m2;
  cout << m2.CalculateMedian(24, 22, 21, 23, 20) << endl;
  cout << m2.CalculateMedian(12, 18, 9, 3) << endl;
  cout << m2.CalculateMedian(0, 1, 0) << endl;
  cout << m2.CalculateMedian(5, 3) << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}
