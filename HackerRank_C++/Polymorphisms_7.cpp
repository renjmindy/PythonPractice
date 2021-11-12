#include <iostream>
using namespace std;

//add class definitions below this line

class Chef {
  public:
  
  //add constructors below this line
  
    Chef(string na) {
      name = na;
    }
  
    Chef(string na, string cu) {
      name = na;
      cuisine = cu;
    }
  
    Chef(string na, string cu, int ms) {
      name = na;
      cuisine = cu;
      michelinStars = ms;
    } 

  //add constructors above this line
  
    string GetName() {
      return name;
    }

    string GetCuisine() {
      return cuisine;
    }

    int GetStars() {
      return michelinStars;
    }

    void Display() {
      cout << GetName() << " is known for " << GetCuisine() << " cuisine and has " << GetStars() << " Michelin stars." << endl;
    }
  
  private:
    string name = "null";
    string cuisine = "null";
    int michelinStars = 0;
};

//add class definitions above this line


int main() {
  
  //DO NOT EDIT code below this line
   
  Chef c1("Marco Pierre White");
  Chef c2("Rene Redzepi", "Nordic");
  Chef c3("Thomas Keller", "French", 3);
    
  c1.Display();
  c2.Display();
  c3.Display();
  
  //DO NOT EDIT code above this line
  
  return 0;
  
}
