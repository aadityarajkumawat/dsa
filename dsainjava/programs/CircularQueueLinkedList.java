package programs;

class CircularQueueLL {
    private Node front = null;
    private Node rear = null;

    public void traversal() {
        Node _front = front;
        Node _rear = rear;

        if (_front != null) {
            while (_front != _rear) {
                System.out.print(_front.getData() + " ");
                _front = _front.getNext();
            }
            System.out.println(_front.getData() + " ");
        }
    }

    public void enqueue(int x) {
        Node newNode = new Node(x);
        if (front == null && rear == null) {
            newNode.next = newNode;
            front = newNode;
            rear = newNode;
            return;
        }

        rear.next = newNode;
        rear = newNode;
        newNode.next = front;
    }

    public void dequeue() {
        if (front == null && rear == null) {
            System.out.println("Queue is empty");
        } else if (front == rear) {
            front = null;
            rear = null;
        } else {
            rear.next = front.next;
            front = rear.next;
        }
    }

    public int lengthOfQueue() {
        int len = 0;
        if (front == null && rear == null) {
            return 0;
        } else {
            Node _front = front;
            Node _rear = rear;

            while (_front != _rear) {
                _front = _front.getNext();
                len++;
            }

            return len + 1;

        }
    }

    public int peek() {
        if (front == null && rear == null) {
            return 0;
        }

        return front.getData();
    }
}

public class CircularQueueLinkedList {
    public static void main(String[] args) {
        CircularQueueLL cq = new CircularQueueLL();

        cq.traversal();

        cq.enqueue(4);

        cq.enqueue(5);
        cq.enqueue(8);
        cq.enqueue(9);
        cq.enqueue(2);

        cq.traversal();

        cq.dequeue();
        System.out.println("Peek: " + cq.peek());
        cq.dequeue();

        cq.enqueue(11);

        cq.traversal();
        // System.out.println("Length of queue: " + cq.lengthOfQueue());
    }
}
