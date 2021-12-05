#include <iostream>
#include <cassert>
#include <vector>
#include <bits/stdc++.h>
#include <cmath>

long long pisano_period_len(long long m) {
    
    long long p0 = 0;
    long long p1 = 1;
    long long p0s = 0;
    long long p1s = 0;
    long long pLs = 0;
    long long tmp = 0;
    
    for (int i = 0; i < m * m; i++) {
        tmp = p1;
        p1 += p0;
        p0 = tmp;
        
        p1s = (long long) p1 * p1 % m;
        p0s = (long long) p0 * p0 % m;
        
        if (p0s == 0 && p1s == 1) {
            pLs = i + 1;
            break;
        }
    }
    return pLs; 
}

std::vector<int> pisano_period_fast(long long m) {
    std::vector<int> a;
    std::vector<int> b;
    long long p = pisano_period_len(m);
    //std::cout << "period: " << p << std::endl;
    
    a.push_back(0);
    a.push_back(1);
    
    if (m >= 2) {
        for (int i = 2; i < p; i++) {
            a.push_back(a[i-2] + a[i-1]);
        }
    }
    
    //std::cout << "pisano period for mod[" << m << "]: " << std::endl;
    //std::cout << "pisano period for mod[" << m << "]: ";
    for (auto i : a) {
        //std::cout << i << ", " << (long long) i * i << ", " << (long long) i * i % m << std::endl;
        //std::cout << (long long) i * i % m << " ";
        b.push_back((long long) i * i % m);
    }
    //std::cout << "\n";
    
    return b;
} 

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}

int fibonacci_sum_squares_fast(long long n) {
    
    //std::cout << "n: " << n << std::endl;
    int m = 10;
    
    if (n <= 1) {
        return n;
    }
    else {
        long long p = pisano_period_len(m);
        int mul = n / p;
        int rem = n % p;
        //std::cout << "\tmultiplier: " << mul << std::endl;
        //std::cout << "\tremainder: " << rem << std::endl;
        std::vector<int> a = pisano_period_fast(m);
        int suma = std::accumulate(a.begin(), a.end(), 0);
        int sumb = std::accumulate(a.begin(), a.begin()+rem+1, 0);
        //std::cout << "\tsuma: " << suma << std::endl;
        //std::cout << "\tsumb: " << sumb << std::endl;
        //std::cout << "\tmul * suma + sumb: " << (long long) mul * suma + sumb << std::endl;
        //std::cout << "\tmul % 10: " << (long long) mul % m << std::endl;
        //std::cout << "\tsuma % 10: " << suma % m << std::endl;
        //std::cout << "\tsumb % 10: " << sumb % m << std::endl;
        int rem_mul = (long long) mul % m;
        int rem_suma = suma % m;
        int rem_sumb = sumb % m;
        //std::cout << "\trem_mul * rem_suma + rem_sumb: " << rem_mul * rem_suma + rem_sumb << std::endl;
        return rem_mul * rem_suma + rem_sumb;
    }
}

int main() {
    long long n = 0;
    std::cin >> n;
    //std::cout << fibonacci_sum_squares_naive(n) << std::endl;
    //std::cout << "\n";
    std::cout << fibonacci_sum_squares_fast(n) << std::endl;
}
