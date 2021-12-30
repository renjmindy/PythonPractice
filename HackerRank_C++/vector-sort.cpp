#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    vector<int> a;
    int n, nums;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> nums;
        a.push_back(nums);
    }     
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        cout << a.at(i) << " ";
    }
    return 0;
}
