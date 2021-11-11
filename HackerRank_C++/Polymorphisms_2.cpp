#include <iostream>
using namespace std;

//add class definitions below this line

class Shape {
  public:
    virtual double Area() = 0;
  
    double GetBase() {
      return base;
    }
  
    void SetBase(double new_base) {
      base = new_base;
    }
  
    double GetHeight() {
      return height;
    }
  
    void SetHeight(double new_height) {
      height = new_height;
    }
  
  protected:
    double base;
    double height;
};

class Triangle : public Shape {
  public:
    Triangle(double b, double h) {
      base = b;
      height = h;
    }
  
    double Area() {
      return base * height / 2;
    }
};

class Rectangle : public Shape {
  public:
    Rectangle(double b, double h) {
      base = b;
      height = h;
    }
  
    double Area() {
      return base * height;
    }
};

//add class definitions above this line

int main() {
  
  //add code below this line
  
  Triangle t(4, 4);
  cout << t.Area() << endl;
  Rectangle r(4, 4);
  cout << r.Area() << endl;
  
  //Shape s;
  
  //add code above this line
  
  return 0;
  
}
