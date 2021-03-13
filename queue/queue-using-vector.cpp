#include <iostream>
#include <vector>

#define SIZE 5

class Queue
{
private:
  std::vector<int> arr;
  int front;
  int rear;

public:
  Queue()
  {
    arr.reserve(10);
    front = -1;
    rear = -1;
  }

  bool isFull()
  {
    return front == 0 && rear == SIZE - 1;
  }

  bool isEmpty()
  {
    return front == -1 && rear == -1;
  }

  void enQueue(int x)
  {
    if (isFull())
    {
      std::cout << "The queue is full" << std::endl;
      return;
    }

    arr.push_back(x);
    front = 0;
    rear += 1;
  }

  int deQueue()
  {
    if (isEmpty())
    {
      std::cout << "The queue is empty" << std::endl;
      return -1;
    }

    int front_save = front;

    if (front >= rear)
    {
      front = -1;
      rear = -1;
    }
    else
    {
      front += 1;
    }
    std::cout << "Deleted element: " << arr[front_save] << std::endl;
    return arr[front_save];
  }

  void displayQueue()
  {
    if (isEmpty())
    {
      std::cout << "The queue is empty" << std::endl;
      return;
    }
    for (int i = front; i <= rear; i++)
    {
      std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
  }
};

int main()
{
  Queue queue;

  queue.enQueue(2);
  queue.enQueue(3);
  queue.enQueue(7);

  queue.displayQueue();

  queue.deQueue();

  queue.displayQueue();

  queue.enQueue(10);
  queue.enQueue(15);
  queue.enQueue(19);

  queue.displayQueue();

  return 0;
}
