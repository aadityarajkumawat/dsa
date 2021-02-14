#include <iostream>

class Box {
public:
  double length;
  double width;
  double height;

  double getVolume(void);
  void setLength(double len);
  void setWidth(double wid);
  void setHeight(double hei);
};

double Box::getVolume(void) {
  return length * width * height;
}

void Box::setLength(double len) {
  length = len;
}

void Box::setWidth(double wid) {
  width = wid;
}

void Box::setHeight(double hei) {
  height = hei;
}

int main() {
  Box box1;
  double volume = 0.0;

  box1.setLength(10.0);
  box1.setHeight(10.0);
  box1.setWidth(10.0);

  volume = box1.getVolume();

  std::cout << volume << std::endl;

  return 0;
}
