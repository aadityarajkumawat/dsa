#include <iostream>
using namespace std;
/**
 * Drawbacks of implementing Queue using arrays
 * Space is not used effectively
*/
class Queue {
public:
  int size;
  int f, r;
  int* arr;
};

int isFull(Queue* q) {
  if (q->r == q->size - 1) {
    return 1;
  }
  return 0;
}

int isEmpty(Queue* q) {
  if (q->f == q->r) {
    return 1;
  }
  return 0;
}

void enqueue(Queue* q, int val) {
  if (isFull(q)) {
    cout << "Queue is Full" << endl;
  }
  else {
    q->r = q->r + 1;
    q->arr[q->r] = val;
  }
}

int dequeue(Queue* q) {
  if (isEmpty(q)) {
    cout << "Queue is empty" << endl;
    return -1;
  }
  int a = -1;
  (q->f)++;
  a = q->arr[q->f];
  return a;
}

int main() {
  Queue q;
  q.size = 10;
  q.f = q.r = -1;
  q.arr = new int[q.size];

  enqueue(&q, 3);
  enqueue(&q, 7);
  enqueue(&q, 10);

  cout << dequeue(&q) << endl;
  cout << dequeue(&q) << endl;
  cout << dequeue(&q) << endl;

  return 0;
}
