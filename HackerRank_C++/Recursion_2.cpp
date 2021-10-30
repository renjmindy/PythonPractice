#include <iostream>
#include <vector>
using namespace std;

//add function definitions below this line

int ListSum(vector<int>& a) {
  if (a.size() <= 1) {
    return a.at(0);
  }
  else {
    vector<int> b(a.begin()+1, a.begin()+a.size());
    return a.at(0) + ListSum(b);
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  vector<int> nums;
  for (int i = 1; i < argc; i++) {
    nums.push_back(stoi(argv[i]));
  }
  cout << ListSum(nums) << endl;
  return 0;
}
