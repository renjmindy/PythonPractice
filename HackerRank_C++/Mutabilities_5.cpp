#include <iostream>
using namespace std;

//add class definitions below this line

class Subway {
  public:
    Subway() {
      passengers = 0;
      total_fares = 0;
    }
  
    int GetPassengers() {
      return passengers;
    }
  
    void Board(int p) {
      if (p >= 0) {
        total_fares += p * fare;
        passengers += p;
      }
    }
  
    void Disembark(int p) {
      if (p >= 0) {
        if (passengers - p < 0) {
          passengers = 0;
        }
        else {
          passengers -= p;
        }
      }
    }
  
    double GetFares() {
      return total_fares;
    }
    
  private:
    const double fare = 2.40; //variable cannot be reassigned
    int passengers;
    double total_fares;
  
    void CalculateFares(int p) {
      total_fares += p * fare;
    }
    
};

//add class definitions above this line   

int main() {
  
  //DO NOT EDIT code below this line

  Subway s;
  cout << s.GetPassengers() << endl;
  s.Board(23);
  s.Disembark(12);
  cout << s.GetPassengers() << endl;
  cout << s.GetFares() << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}
