#include <iostream>

class Node
{
public:
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Queue
{
    Node *front;
    Node *back;

public:
    Queue()
    {
        front = NULL;
        back = NULL;
    }

    void push(int x)
    {
        Node *n = new Node(x);

        if (front == NULL)
        {
            back = n;
            front = n;
            return;
        }

        back->next = n;
        back = n;
    }

    void pop()
    {
        if (front == NULL)
        {
            std::cout << "Queue underflow" << std::endl;
            return;
        }

        Node *toDelete = front;
        front = front->next;

        delete toDelete;
        return;
    }

    int peek()
    {
        if (front == NULL)
        {
            std::cout << "Queue underflow" << std::endl;
            return -1;
        }

        return front->data;
    }

    bool empty()
    {
        return front == NULL;
    }
};

int main()
{
    Queue q;

    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
    q.pop();
    std::cout << q.peek() << std::endl;
    q.pop();

    std::cout << q.empty() << std::endl;

    return 0;
}
