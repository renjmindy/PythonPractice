#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  cin >> my_string;
  
  string modified = "";
  
  if (my_string.length() % 2 == 0) {
    for (int i = 0; i != my_string.length(); i++) {
      if (i % 2 == 0) {
        modified += my_string.at(i+1);
        modified += my_string.at(i);
      }
    }
  }
  
  cout << modified << endl;

  //add code above this line
  
  return 0;
  
}
