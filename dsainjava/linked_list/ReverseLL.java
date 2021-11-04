package linked_list;

import common.Node;

class LinkedListOperations extends LinkedList {
    /**
     * null <- 4 <- 3 <- 8 <- 2 null p c n
     */
    public Node reverseList() {
        Node prev = null;
        Node curr = head;
        Node nex = head;

        while (nex != null) {
            nex = curr.getNext();
            curr.setNext(prev);
            prev = curr;
            curr = nex;
        }

        return prev;
    }
}

public class ReverseLL {
    public static void main(String[] args) {
        LinkedListOperations list = new LinkedListOperations();

        for (int i = 1; i < 5; i++) {
            list.push(i);
        }

        list.traversal();

        list.reverseList();

        list.traversal();
    }
}
