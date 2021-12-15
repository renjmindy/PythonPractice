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

vector<int> optimal_sequence(int n) {
  std::vector<int> sequence;
  while (n >= 1) {
    sequence.push_back(n);
    if (n % 3 == 0) {
      n /= 3;
    } else if (n % 2 == 0) {
      n /= 2;
    } else {
      n -= 1;
    }
  }
  reverse(sequence.begin(), sequence.end());
  return sequence;
}

vector<int> dynamical_sequence(int n) {
  vector<int> sequence;
  vector<int> table(n + 1);
  
  for (int i = 1; i < n + 1; i++) {
    table.at(i) = table.at(i - 1) + 1;
    if (i % 2 == 0) {
      table.at(i) = min(table.at(i), table.at(i / 2) + 1);
    } 
    if (i % 3 == 0) {
      table.at(i) = min(table.at(i), table.at(i / 3) + 1);
    }
  }
  
  int i = n;
  
  while (i > 1) {
    sequence.push_back(i);
    if (table.at(i) - 1 == table.at(i - 1)) {
      i -= 1;
    }
    else if (i % 2 == 0 && table.at(i) - 1 == table.at(i / 2)) {
      i /= 2; 
    }
    else if (i % 3 == 0 && table.at(i) - 1 == table.at(i /3)) {
      i /= 3;
    }
  }
  
  sequence.push_back(1);
  reverse(sequence.begin(), sequence.end());
  return sequence;
  
}

int main() {
  int n;
  std::cin >> n;
  //vector<int> sequence = optimal_sequence(n);
  vector<int> sequence = dynamical_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
  cout << "\n";
}
