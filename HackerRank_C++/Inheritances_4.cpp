#include <iostream>
using namespace std;

class ClassA {
  public:
    void Hello() {
      cout << "Hello from Class A" << endl;
    }
};

class ClassB : public ClassA {
  public:
    void Hello() {
      cout << "Hello from Class B" << endl;
    }
};

//add class definitions below this line

class ClassC : public ClassB {
  public:
    void Bonjour() {
      cout << "Bonjour" << endl;
    }
    void AuRevor() {
      cout << "Au revoir" << endl;
    }
    void Hello() {
      cout << "Hello from Class C" << endl;
    }
};

//add class definitions above this line

int main() {
  
  //add code below this line

  ClassC c;
  c.Bonjour();
  c.ClassA::Hello();
  c.ClassB::Hello();
  c.AuRevor();
  c.Hello();

  //add code above this line
  
  return 0;
  
}
