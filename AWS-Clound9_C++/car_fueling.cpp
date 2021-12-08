#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>
#include <utility>
#include <iomanip>

using std::cin;
using std::cout;
using std::vector;
using std::max;

using namespace std;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
    int curr_refill = 0;
    int last_refill = 0;
    int nums_refill = 0;
    
    vector<int> x;
    x.push_back(0);
    for (int i = 0; i < stops.size(); i++) {
        x.push_back(stops.at(i));
    }
    x.push_back(dist);
    
    while (curr_refill <= stops.size()) {
        last_refill = curr_refill;
        while (curr_refill <= stops.size() && (x[curr_refill + 1] - x[last_refill]) <= tank) {
            curr_refill += 1;
        }
        if (curr_refill == last_refill) {
            return -1;
        }
        if (curr_refill <= stops.size()) {
            nums_refill += 1;
        }
    }
    return nums_refill;
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";

    return 0;
}
