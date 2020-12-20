#include <iostream>
using namespace std;

class Employee {
private:
  int a, b, c;
public:
  int d, e;
  void setData(int a1, int b1, int c1); // function declaration
  void getData() {
    cout << "The value of a is " << a << endl;
    cout << "The value of b is " << b << endl;
    cout << "The value of c is " << c << endl;
    cout << "The value of d is " << d << endl;
    cout << "The value of e is " << e << endl;
  }
};

void Employee::setData(int a1, int b1, int c1) {
  // a, b, c are the variables defined in private
  a = a1;
  b = b1;
  c = c1;
}

int main() {
  Employee harry;
  // harry.a = 34; this will throw error as `a` is a private variable
  harry.d = 12;
  harry.e = 24;
  harry.setData(1, 2, 4);
  harry.getData();
  return 0;
}