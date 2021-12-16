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
using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  vector<vector<int> > a(str1.size() + 1, vector<int>(str2.size() + 1, 0));
  
  for (int i = 0; i < str1.size() + 1; i++) {
    a[i][0] = i;
  }
  
  for (int i = 0; i < str2.size() + 1; i++) {
    a[0][i] = i;
  }
  
  int cost = 0;
  for (int i = 1; i < str1.size() + 1; i++) {
    for (int j = 1; j < str2.size() + 1; j++) {
      if (str1[i - 1] == str2[j - 1]) {
        cost = 0;
      }
      else {
        cost = 1;
      }
      a[i][j] = min(min(a[i-1][j], a[i][j-1]) + 1, a[i-1][j-1] + cost);
    }
  }
  
  return a[str1.size()][str2.size()];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
}
