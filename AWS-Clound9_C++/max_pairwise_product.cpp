#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // generate some random numbers; generate some random tests automatically

using namespace std;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();
    
    for (int first = 0; first < n; ++first) {
        for (int second = first + 1; second < n; ++second) {
            max_product = max(max_product, (long long)numbers[first] * (long long)numbers[second]);
        }
    }
    
    return max_product;
}

long long MaxPairwiseProductFast(const vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    int max_idx1 = -1;
    int max_idx2 = -1;
    
    for (int i = 0; i < numbers.size(); i++) {
        if (max_idx1 < 0 || numbers.at(i) > numbers.at(max_idx1)) {
            max_idx1 = i;
        }
        else continue;
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (i != max_idx1) {
            if (max_idx2 < 0 || numbers.at(i) > numbers.at(max_idx2)) {
                max_idx2 = i;
            }
            else continue;
        }
        else continue;
    }
    
    max_product = (long long)numbers.at(max_idx1) * (long long)numbers.at(max_idx2);

    return max_product;
}

int main() {
    
    /*while (true) {
        int n = rand() % 1000 + 2;
        cout << n << endl;
        vector<int> a;
        for (int i = 0; i < n; i++) {
            a.push_back(rand() % 100000);
        }
        for (auto i : a) {
            cout << i << ' ';
        }
        cout << '\n';
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);
        if (res1 != res2) {
            cout << "wrong answer: " << res1 << ' ' << res2 << endl;
            break;
        }
        else {
            cout << "OK\n";
        }
    }*/
    
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());

    cout << MaxPairwiseProductFast(numbers) << endl;
    //cout << MaxPairwiseProductFast(vector<int>(100000, 0)) << endl;
    return 0;
}
