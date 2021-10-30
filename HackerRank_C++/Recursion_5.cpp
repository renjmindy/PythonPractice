#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

//add function definitions below this line

int GetMax(vector<int>& a) {
  if (a.size() == 1) {
    return a.at(0);
  }
  else {
    vector<int> b(a.begin()+1, a.end());
    return max(a.at(0), max(b.at(0), GetMax(b)));
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  vector<int> nums;
  for (int i = 1; i < argc; i++) {
    nums.push_back(stoi(argv[i]));
  }
  cout << GetMax(nums) << endl;
  return 0;
}
