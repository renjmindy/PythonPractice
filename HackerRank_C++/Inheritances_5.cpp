#include <iostream>
using namespace std;

//add class definitions below this line

class Line {
  public:
    Line(int l) {
      length = l;
    }
  
    int GetLength() {
      return length;
    }
  
    void DrawLine() {
      for (int i = 0; i < length; i++) {
        cout << '*';
      }
      cout << endl;
    }
  
  private:
    int length;
};

class Box : public Line {
  public:
    Box(int l, int w) : Line(l) {
      width = w;
    }
  
    int GetWidth() {
      return width;
    }
  
    void DrawBox() {
      for (int i = 0; i < width; i++) {
        DrawLine();
      }
    }
  
  private:
    int width;
};

//add class definitions above this line

int main() {
  
  //add code below this line

  //Line line(10);
  //line.DrawLine();
  
  Box box(8, 4);
  box.DrawBox();

  //add code above this line
  
  return 0;
  
}
