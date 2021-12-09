#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <utility>
#include <iomanip>

using namespace std;
using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  //write your code here
  int count = 1;
  
  while (n >= count) {
    //cout << "n: " << n << "\t count:" << count << endl;
    summands.push_back(count);
    n -= count;
    count += 1;
  }
  
  if (n > 0) {
    summands[summands.size()-1] += n;
  }
  
  //for (auto i : summands) {
  //  cout << i << " ";
  //}
  //cout << "\n";
  
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  cout << "\n";
}
