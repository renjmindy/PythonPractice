#include <iostream>
#include <vector>
using namespace std;

//DO NOT EDIT/////////////////////////////////////
class Temperature {                             //
  public:                                       //
    virtual double Celsius(double temp) = 0;    //
    virtual double Fahrenheit(double temp) = 0; //
};                                              //
//////////////////////////////////////////////////

//add class definitions below this line

class Conversion : public Temperature {
  public:
  
    double Celsius(double temp) {
      return (temp - 32)/1.8;
    }
    
    double Fahrenheit(double temp) {
      return (temp * 1.8) + 32;
    }
  
    double ConvertTo(char c, double temp) {
      if (tolower(c) == 'c') {
        return Celsius(temp);
      }
      else if (tolower(c) == 'f') {
        return Fahrenheit(temp);
      }
      else {
        return -0.0001;
      }
    }
    
};

//add class definitions above this line


int main() {
  
  //DO NOT EDIT code below this line
   
  Conversion c;
  cout << c.ConvertTo('c', 212.0) << endl;
  cout << c.ConvertTo('C', 78.0) << endl;
  cout << c.ConvertTo('h', 23.0) << endl;
  cout << c.ConvertTo('F', 0.0) << endl;
  cout << c.ConvertTo('f', 29.0) <<endl;
  cout << c.ConvertTo('3', 112.0) << endl;

  //DO NOT EDIT code above this line
  
  return 0;
  
}
