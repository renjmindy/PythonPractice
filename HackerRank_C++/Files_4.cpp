#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <iomanip>
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char** argv) {

////////// DO NOT EDIT! //////////
  string path = argv[1];        //
//////////////////////////////////  
  
  //add code below this line
  
  vector<string> names;
  vector<int> ages;

  try {
    ifstream file;
    string read;
    file.open(path);
    if (!file) {
      throw runtime_error("File failed to open.");
    }
    while (getline(file, read)) {
      //cout << read + ' ';
      stringstream ss(read);
      int counter_words = 0;
      while (getline(ss, read, '\t')) {
        counter_words += 1;
        if (counter_words == 1) {
          names.push_back(read);
        }
        if (counter_words == 2) {
          ages.push_back(stoi(read));
        }
      }
    }
    file.close();
  }
  
  catch (exception& e) {
    cerr << e.what() << endl;
  }

  cout << "The oldest person is " << names.at(max_element(ages.begin(), ages.end()) - ages.begin()) << '.' << endl;
  
  //add code above this line
  
  return 0;
  
}
