#include <iostream>
#include <vector>
using namespace std;

int main() {
  
  vector<string> oceans(0);
  
  //add code below this line
  oceans.push_back("Pacific");
  oceans.push_back("Atlantic");
  oceans.push_back("Atlantic");
  oceans.at(2) = "Indian";
  oceans.insert(oceans.begin()+3, "Arctic");
  oceans.insert(oceans.begin()+4, "Southern");
  oceans.push_back("Southern");
  oceans.pop_back();


  //add code above this line
  
  for (auto a : oceans) {
    cout << a << endl;
  }
  
  return 0;
  
}
