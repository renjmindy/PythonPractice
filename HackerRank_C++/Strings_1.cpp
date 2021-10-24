#include <iostream>
using namespace std;

int main(int argc, char** argv) {
  
  string my_string = (argv[1]);
  
  //add code below this line

  string string1 = " is the first character and ";
  string string2 = " is the last character";
  
  cout << my_string.at(0) + string1 + my_string.at(my_string.length()-1) + string2 << endl;

  //add code above this line
  
  return 0;
  
}
