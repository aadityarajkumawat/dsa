#include <iostream>
using namespace std;
/**
 * ``````Stack`````
 * (### implemented using arrays ###)
 * Its a linear data-structure
 * The first element-in is the
 * last one to come out
 *
 * A pointer is maintained at
 * the top most element(the last-in)
 *
 * Some common methods on Stack ADT :
 * push() -> adds element to top of stack
 *
 * pop() -> removes an element from top
 *
 * peek(index) -> peek value at a given index
 *
 * isEmpty() / isFull()
*/

class Stack {
public:
  int size;
  int top;
  int* arr;
};

int peek(Stack* ptr, int index);

void printStack(Stack* ptr) {
  for (int i = 0;i < ptr->top + 1; i++) {
    cout << "|  " << peek(ptr, i) << "  |" << endl;
  }
}

int isEmpty(Stack* ptr) {
  if (ptr->top == -1) {
    return 1;
  }
  return 0;
}

int isFull(Stack* ptr) {
  if (ptr->top == ptr->size - 1) {
    return 1;
  }
  return 0;
}

void push(Stack* ptr, int val) {
  if (isFull(ptr)) {
    cout << "Sry! The stack is full" << endl;
  }
  else {
    ptr->top++;
    ptr->arr[ptr->top] = val;
  }
}

int pop(Stack* ptr) {
  if (isEmpty(ptr)) {
    cout << "Sry! The stack is empty" << endl;
    return -1;
  }
  else {
    int val = ptr->arr[ptr->top];
    (ptr->top)--;
    return val;
  }
}

int peek(Stack* ptr, int index) {
  if (isEmpty(ptr)) {
    cout << "Sry! The stack is empty" << endl;
    return -1;
  }
  else {
    return ptr->arr[index];
  }
}

int main() {
  Stack* s = new Stack();
  s->size = 80;
  s->top = -1;
  s->arr = new int[s->size];
  cout << "Stack created successfully!!" << endl;
  push(s, 56);
  push(s, 32);
  push(s, 12);
  push(s, 4);
  cout << "Popped " << pop(s) << " from the stack" << endl;
  cout << "Peeking element at index 1 " << peek(s, 1) << endl;

  printStack(s);
  return 0;
}
