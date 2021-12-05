#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

long long pisano_period_len(long long m) {
    
    long long p0 = 0;
    long long p1 = 1;
    long long pL = 0;
    long long tmp = 0;
    
    for (int i = 0; i < m * m; i++) {
        tmp = p1;
        p1 = (p0 + p1) % m;
        p0 = tmp;
        
        if (p0 == 0 && p1 == 1) {
            pL = i + 1;
            break;
        }
    }
    return pL; 
}

std::vector<int> pisano_period_fast(long long m) {
    std::vector<int> a;
    long long p = pisano_period_len(m);
    //std::cout << "period: " << p << std::endl;
    
    a.push_back(0 % m);
    a.push_back(1 % m);
    
    if (m >= 2) {
        for (int i = 2; i < p; i++) {
            a.push_back((a[i-2] + a[i-1]) % m);
        }
    }
    
    /*std::cout << "pisano period for mod[" << m << "]: "; 
    for (auto i : a) {
        std::cout << i << ' ';
    }
    std::cout << "\n";*/
    
    return a;
} 

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    
    int m = 10;
    
    if (n <= 1) {
        return n;
    }
    else {
        long long p = pisano_period_len(m);
        int mul = n / p;
        int rem = n % p;
        //std::cout << "multiplier: " << mul << std::endl;
        //std::cout << "remainder: " << rem << std::endl;
        std::vector<int> a = pisano_period_fast(m);
        int suma = std::accumulate(a.begin(), a.end(), 0);
        int sumb = std::accumulate(a.begin(), a.begin()+rem+1, 0);
        //std::cout << "suma: " << suma << std::endl;
        //std::cout << "sumb: " << sumb << std::endl;
        //std::cout << "mul * suma + sumb: " << (long long) mul * suma + sumb << std::endl;
        //std::cout << "mul % 10: " << (long long) mul % m << std::endl;
        //std::cout << "suma % 10: " << suma % m << std::endl;
        //std::cout << "sumb % 10: " << sumb % m << std::endl;
        int rem_mul = (long long) mul % m;
        int rem_suma = suma % m;
        int rem_sumb = sumb % m;
        return rem_mul * rem_suma + rem_sumb;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_naive(n) << std::endl;
    std::cout << fibonacci_sum_fast(n) << std::endl;
}
