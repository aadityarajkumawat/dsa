package stack;

import common.Node;

class StackLL {
    private Node top = null;

    public boolean isNull(Node node) {
        return node == null;
    }

    public void push(int x) {
        Node newNode = new Node(x);

        if (isNull(top)) {
            top = newNode;
            return;
        }

        newNode.setNext(top);
        top = newNode;
    }

    public int pop() {
        if (isNull(top)) {
            System.out.println("Stack underflow");
            return -1;
        }

        int temp = top.getData();
        top = top.getNext();
        return temp;

    }

    public void traversal() {
        Node ptr = top;

        while (ptr != null) {
            System.out.println(ptr.getData() + " ");
            ptr = ptr.getNext();
        }
        System.out.println();
    }

    public int peek() {
        if (isNull(top)) {
            System.out.println("Stack undeflow");
            return -1;
        }

        return top.getData();
    }
}

public class StackLLImplementation {
    public static void main(String[] args) {
        StackLL s = new StackLL();

        s.traversal();

        s.push(4);
        s.push(2);
        s.push(9);

        s.traversal();

        s.pop();

        s.traversal();
    }
}
