#include <iostream>
using namespace std;
/**
 * Drawbacks of implementing Queue using arrays
 * Space is not used effectively
 *
 * Circular increment(order = 3)
 * 0->1->2->3->0->1->2->3->0->1....
 * i=(i+1)%order
*/

class Queue {
public:
	int size;
	int f, r;
	int* arr;
};

void enqueue(Queue* q, int val) {
	if ((q->r + 1) % q->size == q->f) {
		cout << "Queue is full" << endl;
	}
	else {
		q->r = (q->r + 1) % (q->size);
		q->arr[q->r] = val;
	}
}

int dequeue(Queue* q) {
	int val = -1;
	if (q->f == q->r) {
		cout << "Queue is empty" << endl;
		return val;
	}
	else {
		q->f = (q->f + 1) % (q->size);
		val = q->arr[q->f];

		return val;
	}
}

int main() {
	Queue q;
	q.size = 10;
	q.f = q.r = -1;
	q.arr = new int[q.size];

	enqueue(&q, 3);
	enqueue(&q, 7);
	enqueue(&q, 14);

	cout << dequeue(&q) << endl;
	cout << dequeue(&q) << endl;
	cout << dequeue(&q) << endl;

	return 0;
}
