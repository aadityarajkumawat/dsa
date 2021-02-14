#include <iostream>

class Line {
public:
  double length;
  void setLength(double len);
  double getLength(void);
protected:
private:
};

class Box {
public:
  double length;
  void setWidth(double wid);
  double getWidth(void);
private:
  double width;
};

double Line::getLength(void) {
  return length;
}

void Box::setWidth(double wid) {
  width = wid;
}

double Box::getWidth(void) {
  return width;
}

void Line::setLength(double len) {
  length = len;
}

int main() {
  Line line;
  Box box;
  box.length = 10.0;
  box.setWidth(10.0);

  std::cout << "Length of box: " << box.length << std::endl;
  std::cout << "Width of box: " << box.getWidth() << std::endl;

  line.setLength(6.0);
  return 0;
}
