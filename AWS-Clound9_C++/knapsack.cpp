#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cassert>
#include <bits/stdc++.h>
#include <cmath>
#include <map>
#include <iterator>
#include <utility>
#include <iomanip>

using namespace std;
using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  for (size_t i = 0; i < w.size(); ++i) {
    if (current_weight + w[i] <= W) {
      current_weight += w[i];
    }
  }
  return current_weight;
}

int dynamical_weight(int W, const vector<int> &w) {
  vector<int> a(W + 1);
  
  for (size_t i = 0; i < w.size(); i++) {
    for (int j = W; j - w[i] >= 0; j--) {
      a[j] = max(a[j], a[j - w[i]] + w[i]);
      //cout << "\t" << j << " " << w[i] << " " << a[j] << " ";
    }
    //cout << "\n";
  }
  return a[W];
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  //std::cout << optimal_weight(W, w) << '\n';
  cout << dynamical_weight(W, w) << endl;
}
