package linked_list;

import java.util.Scanner;

public class LinkedListImplementation {
    @SuppressWarnings({ "resource" })
    public static void main(String[] args) {
        Scanner ip = new Scanner(System.in);
        char ch = ' ';

        LinkedList list = new LinkedList();

        do {
            System.out.println("````linked list operations:````");
            System.out.println("1. insertion\n2. deletion\n3. traversal\n4. linked list size");
            System.out.print("enter your choice: ");
            int choice = ip.nextInt();

            switch (choice) {
            case 1:
                System.out.println("````insert operations:````");
                do {
                    System.out.println("1. insert at start");
                    System.out.println("2. insert at end");
                    System.out.println("3. insert after a number");
                    System.out.println("4. insert before a number");

                    System.out.print("enter your choice: ");
                    int choice1 = ip.nextInt();
                    System.out.println();

                    int x = 0, y = 0;

                    switch (choice1) {
                    case 1:
                        System.out.println("insert at start");
                        System.out.print("enter the value: ");

                        x = ip.nextInt();
                        list.insertAtStart(x);
                        System.out.println("List:");
                        list.traversal();
                        break;
                    case 2:
                        System.out.println("insert at end");
                        System.out.print("enter the value: ");

                        x = ip.nextInt();
                        list.push(x);
                        System.out.println("List:");
                        list.traversal();
                        break;
                    case 3:
                        System.out.println("insert after a number: ");
                        System.out.print("enter value to be inserted: ");
                        x = ip.nextInt();

                        System.out.print("insert after: ");
                        y = ip.nextInt();

                        list.insertAfter(y, x);
                        System.out.println("List:");
                        list.traversal();
                        break;
                    case 4:
                        System.out.println("insert before a number: ");
                        System.out.print("enter value to be inserted: ");
                        x = ip.nextInt();

                        System.out.print("insert before: ");
                        y = ip.nextInt();

                        list.insertBefore(y, x);
                        System.out.println("List:");
                        list.traversal();
                        break;
                    default:
                        System.out.println("invalid operations!");
                    }

                    System.out.println("do you want to continue insert operations?");
                    ch = ip.next().charAt(0);
                } while (ch == 'y' || ch == 'Y');
                break;

            case 2:
                System.out.println("````deletion operations:````");
                do {
                    System.out.println("1. deletion at start");
                    System.out.println("2. deletion at end");
                    System.out.println("3. delete after a node");
                    System.out.println("4. delete before a node");

                    System.out.print("enter your choice: ");
                    int choice1 = ip.nextInt();
                    System.out.println();

                    int x = 0;

                    switch (choice1) {
                    case 1:
                        System.out.println("deletion at start");

                        list.deleteFromStart();
                        System.out.println("list:");
                        list.traversal();
                        break;
                    case 2:
                        System.out.println("deletion at end");

                        list.deleteFromEnd();
                        System.out.println("list:");
                        list.traversal();
                        break;
                    case 3:
                        System.out.println("delete after a node");
                        System.out.print("delete after: ");
                        x = ip.nextInt();

                        list.deleteAfter(x);
                        System.out.println("list:");
                        list.traversal();
                        break;
                    case 4:
                        System.out.println("delete before a node");
                        System.out.print("delete before: ");
                        x = ip.nextInt();

                        list.deleteBefore(x);
                        System.out.println("list:");
                        break;
                    default:
                        System.out.println("invalid operations!");
                    }

                    System.out.println("do you want to continue deletion operations?");
                    ch = ip.next().charAt(0);
                } while (ch == 'y' || ch == 'Y');
                break;

            case 3:
                System.out.println("list:");
                list.traversal();
                break;
            case 4:
                System.out.println("size of linked list: " + list.getLength());
            }
            System.out.println("do you want to continue?");
            ch = ip.next().charAt(0);
        } while (ch == 'Y' || ch == 'y');
    }
}
