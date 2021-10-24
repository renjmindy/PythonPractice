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
  
  vector<int> data;
  int rows = 0;
  int cols = 0; 

  try {
    ifstream file;
    string read;
    file.open(path);
    if (!file) {
      throw runtime_error("File failed to open.");
    }
    while (getline(file, read)) {
      stringstream ss(read);
      rows += 1;
      cols = 0;
      while (getline(ss, read, ',')) {
        data.push_back(stoi(read));
        cols += 1;
      }
    }
  
    int sum_data[cols];
    for (int i = 0; i < cols; i++) {
      sum_data[i] = 0;
    }
    
    for (int i = 0; i < data.size(); i++) {
      sum_data[i % cols] += data.at(i);
    }
    
    for (int i = 0; i < cols; i++) {
      cout << sum_data[i]/rows << " ";
    }
    
    file.close();
  }
  
  catch (exception& e) {
    cerr << e.what() << endl;
  }
  

  //add code above this line
  
  return 0;
  
}
