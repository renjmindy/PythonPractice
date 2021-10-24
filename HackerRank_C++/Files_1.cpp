#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
using namespace std;

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line

  vector<int> nums;
  int counter_lines = 0;
  int counter_characters = 0;

  try {
    ifstream file;
    string read;
    file.open(path);
    if (!file) {
      throw runtime_error("File failed to open.");
    }
    while (getline(file, read)) {
      stringstream ss(read);
      counter_lines += 1;
      //cout << read << " " << read.length() << endl;
      counter_characters += read.length();
      //while (getline(ss, read, ' ')) {
      //  cout << read << " " << read.length() << endl;
      //  nums.push_back(read.length());
      //}
    }
    //for (int i = 0; i < nums.size(); i++) {
    //  counter_characters += nums.at(i);
    //}
    file.close();
  }
  
  catch (exception& e) {
    cerr << e.what() << endl;
  }
  
  cout << counter_lines << " line(s)" << endl;
  cout << counter_characters << " character(s)" << endl;
  
  //add code above this line
  
  return 0;
  
}
