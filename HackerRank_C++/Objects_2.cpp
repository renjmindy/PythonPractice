#include <iostream>
using namespace std;

//add class definitions below this line
    
class Cat {
  public:
    string breed;
    string color;
    string name;
  
  Cat() {
    breed = "American Shorthair";
    color = "black";
    name = "Kiwi";
  }
};
  
//add class definitions above this line

int main() {

  Cat cat;
  cout << cat.breed << endl;
  cout << cat.color << endl;
  cout << cat.name << endl;

  return 0;
  
}
