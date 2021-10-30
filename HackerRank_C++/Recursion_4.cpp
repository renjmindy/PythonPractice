#include <iostream>
using namespace std;

//add function definitions below this line

string ReverseString(string a) {
  if (a.length() < 1) {
    return "";
  }
  else {
    return a.substr(a.length()-1) + 
      ReverseString(a.substr(0, a.length()-1));
  }
}

//add function definitions above this line

int main(int argc, char** argv) {
  cout << ReverseString(argv[1]) << endl;
  return 0;
}
