package programs;

public class LinkedList {
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
