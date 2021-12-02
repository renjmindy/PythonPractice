#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
    int n = numbers.size();

    //for (int first = 0; first < n; ++first) {
    //    for (int second = first + 1; second < n; ++second) {
    //        max_product = std::max(max_product, (long long)numbers[first] * (long long)numbers[second]);
    //    }
    //}

    int max_idx1 = -1;
    int max_idx2 = -1;
    
    for (int i = 0; i < numbers.size(); i++) {
        if (max_idx1 < 0 || numbers.at(i) > numbers.at(max_idx1)) {
            max_idx1 = i;
        }
        else {
            continue;
        }
    }
    
    for (int i = 0; i < numbers.size(); i++) {
        if (i != max_idx1) {
            if (max_idx2 < 0 || numbers.at(i) > numbers.at(max_idx2)) {
                max_idx2 = i;
            }
            else {
                continue;
            }
        }
        else {
            continue;
        }
    }
    
    max_product = (long long)numbers.at(max_idx1) * (long long)numbers.at(max_idx2);

    return max_product;
}

int main() {
    /*int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }
    
    sort(numbers.begin(), numbers.end());

    std::cout << MaxPairwiseProduct(numbers) << "\n";*/
    cout << MaxPairwiseProduct(vector<int>(100000, 0)) << endl;
    return 0;
}
