#include <iostream>
#include <vector>
using namespace std;

//add code below this line

void GetOddsEvens(string a, vector<int>& b) {
  if (a == "true") {
    for (int i = 0; i < b.size(); i++) {
      if (b.at(i) % 2 == 0) {
        cout << b.at(i) << endl;
      }
    }
  } else if (a == "false") {
    for (auto val : b) {
      if (val % 2 > 0) {
        cout << val << endl;
      }
    }
  } else {
    cout << "Command was successfully executed." << endl;
  }
}

//add code above this line

int main(int argc, char** argv) {
  string x = argv[1];
  vector<int> y;
  for (int i = 2; i < argc; i++) {
    y.push_back(stoi(argv[i]));
  }
  GetOddsEvens(x, y);
}
