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

int lcs2(vector<int> &a, vector<int> &b) {
  //write your code here
  vector<vector<int> > dp(a.size() + 1, vector<int>(b.size() + 1, 0));
  
  for (int col = b.size() - 1; col >= 0; col--) {
    for (int row = a.size() - 1; row >= 0; row--) {
      if (a.at(row) == b.at(col)) {
        dp[row][col] = 1 + dp[row+1][col+1];
      }
      else {
        dp[row][col] = max(dp[row+1][col], dp[row][col+1]);
      }
    }
  }
  
  return dp[0][0];
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }

  size_t m;
  std::cin >> m;
  vector<int> b(m);
  for (size_t i = 0; i < m; i++) {
    std::cin >> b[i];
  }

  std::cout << lcs2(a, b) << std::endl;
}
