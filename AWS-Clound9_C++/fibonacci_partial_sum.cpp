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
    
    //std::cout << "pisano period for mod[" << m << "]: "; 
    //for (auto i : a) {
    //    std::cout << i << ' ';
    //}
    //std::cout << "\n";
    
    return a;
} 

long long fibonacci_sum_fast(long long n) {
    
    //std::cout << "n: " << n << std::endl;
    int m = 10;
    
    if (n <= 1) {
        return n;
    }
    else {
        long long p = pisano_period_len(m);
        long long mul = n / p;
        long long rem = n % p;
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
        //long long rem_mul = (long long) mul % m;
        //long long rem_suma = suma % m;
        //long long rem_sumb = sumb % m;
        //std::cout << "\trem_mul * rem_suma + rem_sumb: " << rem_mul * rem_suma + rem_sumb << std::endl;
        //return rem_mul * rem_suma + rem_sumb;
        return (long long) mul * suma + sumb;
    }
}

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current;
    }

    return sum % 10;
}

long long get_fibonacci_partial_sum_fast(long long from, long long to) {
    
    if (from == 0 && to == 0) {
        return 0;
    }
    
    long long sum_ini = 0; 
    
    if (from > 0) {
        sum_ini = fibonacci_sum_fast(from-1);
    } 
    long long sum_end = fibonacci_sum_fast(to);
    
    //std::cout << "sum_ini: " << sum_ini << std::endl;
    //std::cout << "sum_end: " << sum_end << std::endl;
    //std::cout << "diff(1): " << (long long) (sum_end - sum_ini) << std::endl;
    long long final = sum_end - sum_ini;
    //std::cout << "diff(2): " << final << std::endl;
    return abs(final % 10);
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    //std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';
    std::cout << get_fibonacci_partial_sum_fast(from, to) << std::endl;
}
