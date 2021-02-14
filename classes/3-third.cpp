#include <iostream>

// Parent Class
class Box {
protected:
  double width;
};

// Derived Class
class SmallBox :Box {
public:
  void setSmallWidth(double wid);
  double getSmallWidth(void);
};

double SmallBox::getSmallWidth(void) {
  return width;
}

void SmallBox::setSmallWidth(double wid) {
  width = wid;
}

int main() {
  SmallBox box;
  box.setSmallWidth(5.0);
  std::cout << "Width of box: " << box.getSmallWidth() << std::endl;
  return 0;
}
