#include <iostream>
using namespace std;

//add class definitions below this line

class Mass {
  public:
    Mass(double mg, double g, double kg) {
      milligrams = mg;
      grams = g;
      kilograms = kg;
    }
  
    double TotalWeight() {
      return milligrams*0.001 + grams*1. + kilograms*1000.;
    }
  
    string CompareWeight(Mass m) {
      if (TotalWeight() > m.TotalWeight()) {
        return "The first object is heavier.";
      }
      else if (TotalWeight() < m.TotalWeight()) {
        return "The second object is heavier.";
      }
      else {
        return "The two objects weight the same.";
      }
    }
  
  private:
    double milligrams;
    double grams;
    double kilograms;
};

//add class definitions above this line   

int main() {
  
  //DO NOT EDIT the code below

  Mass m1(800, 17, 3);
  Mass m2(730, 38, 2);
  cout << m1.TotalWeight() << endl;
  cout << m2.TotalWeight() << endl;
  cout << m1.CompareWeight(m2) << endl;

  //DO NOT EDIT the code above
  
  return 0;
  
}
