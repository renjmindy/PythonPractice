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

  vector<string> text;

  try {
    ifstream file;
    string read;
    file.open(path);
    if (!file) {
      throw runtime_error("File failed to open.");
    }
    while (getline(file, read)) { //set delimiter as a period
      text.push_back(read);
    }
    for (int i = text.size()-1; i >= 0; --i) {
      cout << text.at(i) << endl;
    }
    file.close();
  }
  
  catch (exception& e) {
    cerr << e.what() << endl;
  }

  //add code above this line
  
  return 0;
  
}
