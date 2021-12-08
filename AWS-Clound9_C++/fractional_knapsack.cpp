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

using namespace std;

struct Item {
  Item (int v, int w) : value(v), weight(w) {}
  int value, weight;
};

bool comp (struct Item a, struct Item b) {
  return (double)a.value/(double)a.weight > (double)b.value/(double)b.weight;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;
  double weight = 0.0;

  // write your code here
  int nitems = weights.size();
  vector<Item> items;
  for (int i = 0; i < nitems; i++) {
    Item *item = new Item(values.at(i), weights.at(i));
    items.push_back(*item);
  }
  
  sort(items.begin(), items.end(), comp);
  
  //for (const auto &i : items) {
  //  cout << i.value << "\t" << i.weight << "\t" << i.value*1.0/i.weight << endl;
  //}
  
  for (int i = 0; i < nitems; i++) {
    if (weight + items[i].weight <= capacity) {
      weight += items[i].weight;
      value += (double)items[i].value; 
    }
    else {
      value += items[i].value * (double)(capacity - weight) / (double)items[i].weight;
      break;
    }
  }
  
  return value;
}

int main() {
  int n;
  int capacity;
  cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  cout << fixed << setprecision(4) << optimal_value << endl;
  return 0;
}
