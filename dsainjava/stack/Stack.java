package stack;

public class Stack {
    private int top = -1, size;
    private int[] arr;

    public Stack(int size) {
        this.size = size;
        this.arr = new int[size];
    }

    public boolean overflow() {
        return top == size - 1;
    }

    public boolean underflow() {
        return top == -1;
    }

    public void push(int x) {
        if (overflow()) {
            System.out.println("Stack is full");
        } else {
            top++;
            System.out.println("top: " + top);
            arr[top] = x;
        }
    }

    public void pop() {
        if (underflow()) {
            System.out.println("Stack is empty");
        } else {
            top--;
        }
    }

    public int peek() {
        if (top != -1)
            return -1;
        return arr[top];
    }

    public void display() {
        for (int i = top; i > -1; i--) {
            System.out.print(arr[i] + " ");
        }
        System.out.println();
    }
}
