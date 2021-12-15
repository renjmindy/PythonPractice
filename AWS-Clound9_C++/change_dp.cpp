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

int get_change(int m) {
  //write your code here
  vector<int> coins;
  coins.push_back(1);
  coins.push_back(3);
  coins.push_back(4);
  
  int table[m + 1];
  
  table[0] = 0;
  
  for (int i = 1; i < m + 1; i++) {
    table[i] = INT_MAX;
  }
  
  for (int i = 1; i < m + 1; i++) {
    for (int j = 0; j < coins.size(); j++) {
      if (coins.at(j) <= i) {
        if (table[i - coins.at(j)] != INT_MAX && table[i - coins.at(j)] + 1 < table[i]) {
          table[i] = table[i - coins.at(j)] + 1;
        }
      }
    }
  }
  
  if (table[m] == INT_MAX) {
    return -1;
  }
  
  return table[m];
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
