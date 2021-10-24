#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  cin >> my_string;
  
  for (int i = 0; i != int(my_string.length()/2); i++) {
    cout << my_string.at(i);
  }
  
  cout << '\n';
  
  for (int i = int(my_string.length()/2); i != my_string.length(); i++) {
    cout << my_string.at(i);
  }

  //add code above this line
  
  return 0;
  
}
