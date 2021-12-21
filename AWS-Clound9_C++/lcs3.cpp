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

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  vector<vector<vector<int> > > dp(a.size() + 1, vector<vector<int> >(b.size() + 1, vector<int>(c.size() + 1, 0)));
  
  for (int hit = c.size() - 1; hit >= 0; hit--) {
    for (int col = b.size() - 1; col >= 0; col--) {
      for (int row = a.size() - 1; row >= 0; row--) {
        if (a.at(row) == b.at(col) && b.at(col) == c.at(hit)) {
          dp[row][col][hit] = 1 + dp[row+1][col+1][hit+1];
        }
        else {
          dp[row][col][hit] = max(dp[row+1][col][hit], max(dp[row][col+1][hit], dp[row][col][hit+1]));
        }
      }
    }
  }
  
  return dp[0][0][0];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
