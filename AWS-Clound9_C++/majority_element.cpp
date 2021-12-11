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

int get_majority_element(vector<int> &a, int left, int right) {
  if (left > right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  
  sort(a.begin(), a.end());
  
  int mid = left + (right - left - 1) / 2;
  int counter = 0;
  
  for (int i = 0; i < a.size(); i++) {
    if (a.at(i) == a.at(mid)) {
      counter += 1;
    }
  }
  
  return (counter > (int)(0.5*a.size())) ? mid : -1;
  
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
