#include <iostream>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>

std::vector<int> pisano_period_fast(long long m) {
    std::vector<int> a;
    
    a.push_back(0 % m);
    a.push_back(1 % m);
    
    if (m >= 2) {
        for (int i = 2; i < m * m; i++) {
            a.push_back((a[i-2] + a[i-1]) % m);
        }
    }
    
    //std::cout << "pisano period for mod[" << m << "]: "; 
    //for (auto i : a) {
    //    std::cout << i << ' ';
    //}
    //std::cout << "\n";
    
    return a;
} 

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1) {
        return n;
    }
    else {
        int rem = n % ((m * m) - 1);
        std::vector<int> a = pisano_period_fast(m);
        return a[rem];
    }
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    //std::cout << get_fibonacci_huge_naive(n, m) << '\n';
    std::cout << get_fibonacci_huge_fast(n, m) << std::endl;
}
