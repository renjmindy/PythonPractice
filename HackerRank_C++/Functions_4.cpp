#include <iostream>
#include <vector>
using namespace std;

//add code below this line

bool IsPalindrome(string a) {
  string b = ""; 
  for (int i = a.length()-1; i >= 0; --i) {
    b += a[i];
  }
  if (a == b) {
    return true;
  }
  else {
    return false;
  }
}

//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  cout << boolalpha << IsPalindrome(x) << endl;
}
