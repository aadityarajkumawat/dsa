#include <iostream>

class Line {
public:
  int getLength(void);
  Line(int len);
  Line(const Line& obj);
  ~Line();

private:
  int* ptr;
};

Line::Line(int len) {
  std::cout << "Creating an object" << std::endl;

  ptr = new int;
  *ptr = len;
}

Line::Line(const Line& obj) {
  std::cout << "Copy Constructor" << std::endl;
  ptr = new int;
  *ptr = *obj.ptr;
}

Line::~Line(void) {
  std::cout << "Freeing Memory" << std::endl;
  delete ptr;
}

int Line::getLength(void) {
  return *ptr;
}

void display(Line obj) {
  std::cout << "Length of line: " << obj.getLength() << std::endl;
}

int main() {
  Line line(10);
  display(line);
  return 0;
}
