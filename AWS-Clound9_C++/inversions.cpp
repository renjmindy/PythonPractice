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

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t mid, size_t right) {
  long long counter = 0;
  size_t i = left, j = mid, k = left;
  
  while (i <= mid - 1 && j <= right) {
    if (a[i] <= a[j]) {
      b[k++] = a[i++];
    }
    else {
      b[k++] = a[j++];
      counter += (mid - i);
    }
  }
  
  while (i <= mid - 1) {
    b[k++] = a[i++];
  }
  
  while (j <= right) {
    b[k++] = a[j++];
  }
  
  for (int i = left; i < right + 1; i++) {
    a[i] = b[i];
  }
  
  return counter;
  
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  //cout << "(0): " << number_of_inversions << " - " << left << " " << ave << " " << right << endl;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  //cout << "(1): " << number_of_inversions << " - " << left << " " << ave << " " << right << endl;
  //for (auto i : b) {
  //  cout << "\t(1-1) b: " << i << endl;
  //}
  number_of_inversions += get_number_of_inversions(a, b, ave + 1, right);
  //cout << "(2): " << number_of_inversions << " - " << left << " " << ave << " " << right << endl;
  //for (auto i : b) {
  //  cout << "\t(2-1) b: " << i << endl;
  //}
  //write your code here
  //cout << "\t---------\n";
  number_of_inversions += merge(a, b, left, ave + 1, right);
  //for (auto i : a) {
  //  cout << "\t(2-2) a: " << i << endl;
  //}
  return number_of_inversions;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  vector<int> b(a.size());
  std::cout << get_number_of_inversions(a, b, 0, a.size() - 1) << '\n';
}
