class DNode {
    private int data;
    private DNode prev;
    private DNode next;

    DNode() {
        data = 0;
        prev = null;
        next = null;
    }

    DNode(int data) {
        this.data = data;
        prev = null;
        next = null;
    }

    DNode(int data, DNode next) {
        this.data = data;
        this.next = next;
    }

    DNode(int data, DNode next, DNode prev) {
        this.data = data;
        this.next = next;
        this.prev = prev;
    }

    public void setNext(DNode next) {
        this.next = next;
    }

    public DNode getNext() {
        return next;
    }

    public void setPrev(DNode prev) {
        this.prev = prev;
    }

    public DNode getPrev() {
        return prev;
    }

    public void setData(int data) {
        this.data = data;
    }

    public int getData() {
        return data;
    }
}

class DoublyLinkedList {
    private DNode head = null;
    private DNode tail = null;

    /** Insertion */
    public void insertAtStart(int x) {
        DNode newNode = new DNode(x);

        if (head == null && tail == null) {
            head = newNode;
            tail = newNode;
            return;
        }

        newNode.setNext(head);
        head.setPrev(newNode);
        head = newNode;
    }

    public void insertAtEnd(int x) {
        DNode newNode = new DNode(x);

        if (head == null && tail == null) {
            head = newNode;
            tail = newNode;
            return;
        }

        tail.setNext(newNode);
        newNode.setPrev(tail);
        tail = newNode;
    }

    public void insertAfter(int x, int y) {
        DNode newNode = new DNode(y);
        DNode ptr = head;

        while (ptr.getData() != x) {
            ptr = ptr.getNext();
        }

        if (ptr.getNext() != null)
            ptr.getNext().setPrev(newNode);
        newNode.setNext(ptr.getNext());
        newNode.setPrev(ptr);
        ptr.setNext(newNode);
    }

    public void insertBefore(int x, int y) {
        DNode newNode = new DNode(y);
        DNode ptr = head;

        while (ptr.getData() != x) {
            ptr = ptr.getNext();
        }

        if (ptr.getPrev() != null)
            ptr.getPrev().setNext(newNode);
        newNode.setPrev(ptr.getPrev());
        newNode.setNext(ptr);
        ptr.setPrev(newNode);
    }

    /** Deletion */
    public void deleteFromStart() {
    }

    public void deleteFromEnd() {
    }

    public void deleteAfter(int x) {
    }

    public void deleteBefore(int x) {
    }

    public void traversal() {
        DNode ptr = head;

        while (ptr != null) {
            System.out.print(ptr.getData() + " ");
            ptr = ptr.getNext();
        }

        System.out.println();
    }
}

public class DoublyLinkedListImpl {
    public static void main(String[] args) {
        DoublyLinkedList l = new DoublyLinkedList();

        // l.insertAtStart(5);
        // l.insertAtStart(4);

        l.insertAtEnd(1);
        l.insertAtEnd(2);
        l.insertAtStart(0);
        l.insertAtEnd(4);

        l.insertAfter(4, 55);

        l.insertBefore(1, 44);
        l.insertBefore(0, 99);

        l.traversal();
    }
}
