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

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size() - 1; 
  //write your code here
  int lindex = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (x == a[mid]) {
      lindex = mid;
      right = mid - 1;
    }
    else if (x > a[mid]) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  
  int rindex = -1;
  while (left <= right) {
    int mid = left + (right - left) / 2;
    if (x == a[mid]) {
      rindex = mid;
      left = mid + 1;
    }
    else if (x > a[mid]) {
      left = mid + 1;
    }
    else {
      right = mid - 1;
    }
  }
  
  if (lindex == -1 && rindex == -1) {
    return -1;
  } 
  else if (lindex >= 0 && rindex >= 0) {
    return lindex;
  }
  else {
    return (lindex >= 0) ? lindex : rindex;
  }
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    //std::cout << linear_search(a, b[i]) << ' ';
    cout << binary_search(a, b[i]) << " ";
  }
  cout << "\n";
}
