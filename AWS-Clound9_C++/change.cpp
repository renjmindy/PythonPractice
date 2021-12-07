#include <iostream>

int get_change(int m) {
  //write your code here
  
  int count_ten = 0;
  int count_five = 0;
  int count_one = 0;
  int n = 0;
  
  while (m > 0) {
    if (m >= 10) {
      m -= 10;
      count_ten += 1;
    }
    else if (m < 10 and m >= 5 ) {
      m -= 5;
      count_five += 1;
    }
    else {
      m -= 1;
      count_one += 1;
    }
  }
  
  n = count_ten + count_five + count_one;
  
  return n;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
}
