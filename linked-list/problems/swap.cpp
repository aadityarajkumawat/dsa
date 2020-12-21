#include <iostream>
using namespace std;

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int withoutUsingPointer1(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
  return a;
}

int withoutUsingPointer2(int a, int b) {
  int temp = a;
  a = b;
  b = temp;
  return b;
}

int main() {
  int a = 33;
  int b = 16;
  cout << a << " " << b << " " << endl;
  swap(&a, &b);
  cout << a << " " << b << " " << endl;
  cout << "This is cool" << endl;
  cout << "SUM:" << withoutUsingPointer1(a, b) + withoutUsingPointer2(a, b) << endl;
  return 0;
}
