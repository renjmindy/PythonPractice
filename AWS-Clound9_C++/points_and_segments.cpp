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

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

/*vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  int i = 0, j = 0, k = 0;
  for (i = 0; i < points.size(); i++) {
    k = 0;
    for (j = 0; j < starts.size(); j++) {
      if (points.at(i) >= starts.at(j) && points.at(i) <= ends.at(j)) {
        k++;
      }
      else if (points.at(i) < starts.at(j)) {
        j = starts.size();
      }
    }
    cnt.at(i) = k;
  }
  return cnt;
}*/

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  //write your code here
  vector<pair<int, int> > pts, segs;
  for (int i = 0; i < points.size(); i++) {
    pts.push_back({points.at(i), i});
  }
  for (int i = 0; i < starts.size(); i++) {
    segs.push_back({starts.at(i), 1});
    segs.push_back({ends.at(i) + 1, -1});
  }
  sort(pts.begin(), pts.end()); // asc
  sort(segs.begin(), segs.end(), greater<pair<int, int>>()); // desc
  
  int counts = 0;
  for (int i = 0; i < points.size(); i++) {
    while (!segs.empty() && segs.back().first <= pts.at(i).first) {
      counts += segs.back().second;
      segs.pop_back();
    }
    cnt[pts.at(i).second] = counts;
  }
  
  return cnt;
}

int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  //vector<int> cnt = naive_count_segments(starts, ends, points);
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  cout << "\n";
}
