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
using std::string;

bool comp(string a, string b) {
  
  /*int ap = a;
  int bp = b;
  
  while (a >= 10) {
    a /= 10;
  }
  while (b >= 10) {
    b /= 10;
  }
  
  if (a == b) {
    ap %= 10;
    bp %= 10;
    return ap > bp;
  }
  else {
    return a > b;
  }*/
  
  string ab = a.append(b);
  string ba = b.append(a);
  
  //return ab > ba;
  return ab.compare(ba) > 0 ? 1 : 0;
  
}

string largest_number(vector<string> a) {
  //write your code here
  
  sort(a.begin(), a.end(), comp);
  
  std::stringstream ret;
  //vector<int> b;
  
  //cout << "\n";
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
    //cout << stoi(a[i]) << endl;
    //b.push_back(stoi(a.at(i)));
  }
  //cout << "\n";
  
  //sort(b.begin(), b.end(), comp);
  
  string result;
  ret >> result;
  //for (const auto i : b) {
    //cout << i << " ";
    //result += to_string(i);
  //}
  //cout << "\n";
  
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  cout << "\n";
}
