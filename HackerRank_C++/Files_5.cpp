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

  vector<string> cities;
  vector<int> latits;
  int counter_lines = 0;

  try {
    ifstream file;
    string read;
    file.open(path);
    if (!file) {
      throw runtime_error("File failed to open.");
    }
    while (getline(file, read)) {
      stringstream ss(read);
      int counter_words = 0;
      counter_lines++;
      while (getline(ss, read, ',')) {
        counter_words++;
        if (counter_lines > 1 && counter_words == 1) {
          cities.push_back(read);
        }
        if (counter_lines > 1 && counter_words == 3) {
          if (stoi(read) < 0) {
            //cout << counter_lines << endl;
            latits.push_back(counter_lines-2);
          }
        }
      }
    }
    file.close();
  }
  
  catch (exception& e) {
    cerr << e.what() << endl;
  }

  cout << "The following cities are in the Southern Hemisphere: "; 
  for (int i = 0; i < latits.size(); i++) {
    if (i < latits.size()-1) {
      cout << cities.at(latits.at(i)) + ", ";
    } else {
      cout << cities.at(latits.at(i)) + '.';
    }  
  }

  //add code above this line
  
  return 0;
  
}
