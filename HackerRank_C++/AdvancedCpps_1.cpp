#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

//add class definitions below this line

class Greeting {
  public:
    Greeting(string g) {
      greeting = g;
    }
  
    string GetGreeting() {
      return greeting;
    }
  
    void SetGreeting(string new_greeting) {
      greeting = new_greeting;
    }
  
    void PrintGreeting(){
      cout << GetGreeting() << endl;
    }
  
  private:
    string greeting;
};

//add class definitions above this line

#endif

//#include <iostream>
//using namespace std;
#include "class.h"

int main() {
  
  //add code below this line

  //std::cout << "Hello world" << std::endl;
  Greeting g("Hello world");
  cout << g.GetGreeting() << endl;
  g.SetGreeting("Hi world");
  cout << g.GetGreeting() << endl;
  
  
  //add code above this line
  
  return 0;
  
}


#ifndef CLASS_H
#define CLASS_H
#include <iostream>
using namespace std;

//add class definitions below this line

class Greeting {
  public:
    Greeting(string g) {
      greeting = g;
    }
  
    string GetGreeting() {
      return greeting;
    }
  
    void SetGreeting(string new_greeting) {
      greeting = new_greeting;
    }
  
    void PrintGreeting(){
      cout << GetGreeting() << endl;
    }
  
  private:
    string greeting;
};

//add class definitions above this line

#endif
