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

class Farewell {
  public:
    Farewell(string g) {
      farewell = g;
    }
  
    string GetFarewell() {
      return farewell;
    }
  
    void SetFarewell(string new_farewell) {
      farewell = new_farewell;
    }
  
    void PrintFarewell(){
      cout << GetFarewell() << endl;
    }
  
  private:
    string farewell;
};

//add class definitions above this line

#endif

#include "class.h"

int main() {
  
  //add code below this line

  Greeting g("Hello world");
  cout << g.GetGreeting() << endl;
  g.SetGreeting("Hi world");
  cout << g.GetGreeting() << endl;
  
  Farewell f("Goodbye world");
  cout << f.GetFarewell() << endl;
  f.SetFarewell("Bye world");
  cout << f.GetFarewell() << endl;

  //add code above this line
  
  return 0;
  
}
