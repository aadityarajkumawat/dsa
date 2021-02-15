#include <iostream>

class Line {
public:
  void setLength(double len);
  double getLength(void);

  // Constructor
  Line(double len, std::string col);
  // Destructor
  ~Line();

private:
  double length;
  std::string color;
};

// Line::Line(double len) {
//   std::cout << "Object is being created" << std::endl;
//   length = len;
//   std::cout << "Initial length of line: " << length << std::endl;
// }

Line::Line(double len, std::string col) :length(len), color(col) {
  std::cout << "Object is being created" << std::endl;
  std::cout << "Initial length of line: " << length << std::endl;
  std::cout << "Color of line is: " << color << std::endl;
}

void Line::setLength(double len) {
  std::cout << "Setting length of line" << std::endl;
  length = len;
}

double Line::getLength(void) {
  return length;
}

Line::~Line(void) {
  std::cout << "Object is being deleted" << std::endl;
}

int main() {
  Line line(10.0, "red");
  line.setLength(6.0);
  std::cout << "Length of line: " << line.getLength() << std::endl;
  return 0;
}
