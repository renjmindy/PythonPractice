#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string original = (argv[1]);
  string modified;
  char ch;
  
  //add code below this line

  cin >> original;
  
  for (int i = 0; i != original.length(); i++) {
    ch = original.at(i);
    if (isupper(ch)) {
      modified += 'u';
    }
    else if (islower(ch)) {
      modified += 'l';
    }
    else {
      modified += '-';
    }
  }
  
  cout << original << endl;
  cout << modified << endl;

  //add code above this line
  
  return 0;
  
}
