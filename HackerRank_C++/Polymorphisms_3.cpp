class Square {
  public:
    Square(double s) {
      side = s;
    }
    double Area() {
      return side * side;
    }
  private:
    double side;
};

class Rectangle : public Square {
  public:
    Rectangle(double l, double w) : Square(l) {
      length = l;
      width = w;
    }
    double Area() {
      return length * width;
    }
  private:
    double length;
    double width;
};
