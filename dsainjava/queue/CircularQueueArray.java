package queue;

import stack.*;
import java.util.Scanner;

class CircularQueue {
    private int size, front, rear;
    private int[] arr;

    CircularQueue(int size) {
        this.size = size;
        this.front = this.rear - 1;
    }

    public void enqueue(int data) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            System.out.println("Queue is full");
        } else if (front == -1) {
            front = 0;
            rear = 0;
            arr[rear] = data;
        } else {
            rear = (rear + 1);

            if (front <= rear) {
                arr[rear] = data;
            } else {
                arr[rear] = data;
            }
        }
    }

    public int dequeue() {
        int temp;

        if (front == -1) {
            System.out.println("Queue is empty");
            return -1;
        }

        temp = arr[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else if (front == size - 1) {
            front = 0;
        } else {
            front = front + 1;
        }

        return temp;
    }

    public void displayQueue() {
        if (front == -1) {
            System.out.println("Queue is empty");
            return;
        }
        System.out.println("Elements in circular queue are: ");

        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                System.out.println(arr[i]);
                System.out.print(" ");
            }
            System.out.println();
        } else {
            for (int i = front; i < size; i++) {
                System.out.print(arr[i]);
                System.out.print(" ");
            }

            for (int i = 0; i <= rear; i++) {
                System.out.print(arr[i]);
                System.out.print(" ");
            }
            System.out.println();
        }
    }
}

public class CircularQueueArray {
    public static void main(String[] args) {
        char c = ' ';
        Scanner sc = new Scanner(System.in);
        System.out.println("Stack with aray");
        System.out.println("Enter the size of stack:");
        int n = sc.nextInt();

        Stack s = new Stack(n);

        do {
            System.out.println("Stack Operations");
            System.out.println("1. Push Operation \n" + "2. Pop Operation \n" + "3. Overflow Check \n"
                    + "4. Underflow Check \n" + "5. Peek \n" + "6. Display \n");
            int choice = sc.nextInt();
            switch (choice) {
            case 1:
                System.out.println("Push Operation\ninput a number:");
                int val = sc.nextInt();
                s.push(val);
                break;
            case 2:
                System.out.println("Pop Operation");
                s.pop();
                break;
            case 3:
                System.out.println("Overflow Check: " + s.overflow());
                break;
            case 4:
                System.out.println("Underflow Check: " + s.underflow());
                break;
            case 5:
                System.out.println("Peek: " + s.peek());
                break;
            case 6:
                System.out.println("Display");
                s.display();
                break;
            default:
                System.out.println("invalid input");
            }
            s.display();
            System.out.println("\nDo you want to continue(y/ n)");
            c = sc.next().charAt(0);
        } while (c == 'y' || c == 'Y');

        sc.close();
    }
}
