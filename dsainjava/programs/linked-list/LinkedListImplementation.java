import java.util.Scanner;

class Node {
    protected int data;
    public Node next;

    public Node() {
        data = 0;
        next = null;
    }

    public Node(int data) {
        this.data = data;
        next = null;
    }

    public Node(int data, Node next) {
        this.data = data;
        this.next = next;
    }

    public void setData(int data) {
        this.data = data;
    }

    public int getData() {
        return data;
    }

    public void setNext(Node next) {
        this.next = next;
    }

    public Node getNext() {
        return next;
    }
}

class LinkedList {
    public Node head = null;
    public Node tail = null;

    public void traversal() {
        Node ptr = head;
        while (ptr != null) {
            String end = " ";
            if (ptr.getNext() != null) {
                end = " → ";
            }
            System.out.print(ptr.getData() + end);
            ptr = ptr.getNext();
        }
        System.out.println();
    }

    public Node getHead() {
        return head;
    }

    public Node getTail() {
        return tail;
    }

    public void push(int x) {
        Node newNode = new Node(x);
        if (head == null && tail == null) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail.setNext(newNode);
        tail = newNode;
    }

    public void insertAtStart(int x) {
        Node newNode = new Node(x);
        if (head == null && tail == null) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode.setNext(head);
        head = newNode;
    }

    public void insertAfter(int x, int y) {
        Node ptr = head;

        while (ptr != null && ptr.getData() != x) {
            ptr = ptr.getNext();
        }

        if (ptr != null && ptr.getData() == x) {
            Node newNode = new Node(y);
            newNode.setNext(ptr.getNext());
            ptr.setNext(newNode);
        } else {
            System.out.println("number not found");
        }
    }

    public void insertBefore(int x, int y) {
        Node ptr = head;

        if (ptr == null) {
            System.out.println("list is empty");
            return;
        } else if (ptr != null && ptr.getData() == x) {
            insertAtStart(y);
            return;
        }

        while (ptr != null && ptr.getNext() != null && ptr.getNext().getData() != x) {
            ptr = ptr.getNext();
        }

        if (ptr != null && ptr.getNext() != null && ptr.getNext().getData() == x) {
            Node newNode = new Node(y);
            newNode.setNext(ptr.getNext());
            ptr.setNext(newNode);
        } else {
            System.out.println("number not found");
        }
    }

    public void deleteFromEnd() {
        if (head == null && tail == null) {
            System.out.println("list is empty");
            return;
        }

        Node ptr = head;
        while (ptr.getNext().getNext() != null) {
            ptr = ptr.getNext();
        }

        tail = ptr;
        tail.setNext(null);
    }

    public void deleteFromStart() {
        if (head == null && tail == null) {
            System.out.println("list is empty");
            return;
        }

        if (head == null) {
            head = null;
            tail = null;
            return;
        }

        if (head.getNext() == null) {
            head = null;
            tail = null;
        } else {
            head = head.getNext();
        }
    }

    public void deleteAfter(int x) {
        Node ptr = head;

        while (ptr != null && ptr.getData() != x) {
            ptr = ptr.getNext();
        }

        if (ptr != null && ptr.getNext() != null && ptr.getData() == x) {
            ptr.setNext(ptr.getNext().getNext());
        } else {
            System.out.println("number not found");
        }
    }

    public void deleteBefore(int x) {
        Node ptr = head;
        Node qtr = ptr;

        while (ptr != null && ptr.getNext() != null && ptr.getNext().getData() != x) {
            qtr = ptr;
            ptr = ptr.getNext();
        }

        qtr.setNext(ptr.getNext());
    }

    public int getLength() {
        int len = 0;
        Node ptr = head;

        while (ptr != null) {
            ptr = ptr.next;
            len++;
        }

        return len;
    }
}

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
