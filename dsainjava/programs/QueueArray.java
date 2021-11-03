package programs;

import java.util.Scanner;

class ArrayQueue {
    private int[] queue;
    int size, f, r;

    public ArrayQueue(int n) {
        size = n;
        f = -1;
        r = -1;
        queue = new int[size];
    }

    public boolean overflow() {
        return r == size - 1;
    }

    public boolean underflow() {
        return (f == -1 && r == -1);
    }

    public void enqueue(int x) {
        if (this.overflow()) {
            System.out.println("Queue is full");
        } else if (this.underflow()) {
            f = 0;
            r = 0;
            queue[r] = x;
        } else {
            r = r + 1;
            queue[r] = x;
        }
    }

    public void dequeue() {
        if (this.underflow()) {
            System.out.println("Queue is already empty");
        } else if (f == r) {
            int temp = queue[f];
            System.out.println("Item dequeued = " + temp);
            f = -1;
            r = -1;
        } else {
            int temp = queue[f];
            System.out.println("Item dequeued = " + temp);
            f = f + 1;
        }
    }

    public int peek() {
        if (f != -1) {
            return queue[f];
        }
        return -1;
    }

    public void display() {
        if (this.underflow()) {
            System.out.println("Queue is empty");
        }
        for (int i = f; i < r + 1; i++) {
            System.out.print(queue[i] + " ");
        }
        System.out.println("\n");
    }
}

public class QueueArray {
    public static void main(String[] args) {
        char c = ' ';
        Scanner sc = new Scanner(System.in);
        System.out.println("Queue with array");
        System.out.println("Enter the size of queue:");
        int n = sc.nextInt();

        ArrayQueue q = new ArrayQueue(n);
        do {
            System.out.println("Queue Operations");
            System.out.println("1. Enqueue \n" + "2. Dequeue \n" + "3. Peek \n" + "4. display \n"
                    + "5. Overflow Check \n" + "6. Underflow \n");
            int choice = sc.nextInt();
            switch (choice) {
            case 1:
                System.out.println("Enqueue operation\ninput a number:");
                int val = sc.nextInt();
                q.enqueue(val);
                break;
            case 2:
                System.out.println("Dequeue operation");
                q.dequeue();
                break;
            case 3:
                System.out.println("Peek Operation: " + q.peek());
                break;
            case 4:
                System.out.println("Display operation");
                q.display();
                break;
            case 5:
                System.out.println("Overflow status: " + q.overflow());
                break;
            case 6:
                System.out.println("Empty status: " + q.underflow());
                break;
            default:
                System.out.println("invalid input");

            }
            q.display();
            System.out.println("\n Do you want to continue(y/n)");
            c = sc.next().charAt(0);
        } while (c == 'y' || c == 'Y');

        sc.close();
    }
}
