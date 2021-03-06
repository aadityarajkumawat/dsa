#include <iostream>
#include <vector>

#define n 100

class Stack
{
    int *arr;
    int top;

public:
    Stack()
    {
        arr = new int[n];
        top = -1;
    }

    void push(int x)
    {
        if (top == n - 1)
        {
            std::cout << "Stack Overflow" << std::endl;
            return;
        }

        top++;
        arr[top] = x;
    }

    void pop()
    {
        if (top == -1)
        {
            std::cout << "No element to pop" << std::endl;
            return;
        }

        top--;
    }

    int Top()
    {
        if (top == -1)
        {
            std::cout << "No element at top" << std::endl;
            return -1;
        }
        return arr[top];
    }

    bool empty()
    {
        return top == -1;
    }
};

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    std::cout << st.Top() << std::endl;

    st.pop();
    st.pop();

    std::cout << st.Top() << std::endl;

    st.pop();

    std::cout << st.Top() << std::endl;
    return 0;
}
