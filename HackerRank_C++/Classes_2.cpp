#include <iostream>
using namespace std;

//add class definitions below this line

class Student {
  public: 
    Student() {
      name;
      grade;
    }
  
    void ChangeName(string n) { // Setter & Actiona
      name = n;
    }
  
    string ReturnName() { // Getter & Print
      return name;
    }
  
  private:
    string name = "Alice";
    int grade = 4;
    int score = 65;
};

//add class definitions above this line

int main() {
  
  //add code below this line

  Student steve;
  steve.ChangeName("Steve");
  cout << steve.ReturnName() << endl;

  //add code above this line
  
  return 0;
  
}
