package tree;

class Node {
    private int data;
    private Node left;
    private Node right;

    Node(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }

    Node(int data, Node left, Node right) {
        this.data = data;
        this.left = left;
        this.right = right;
    }

    public void setData(int data) {
        this.data = data;
    }

    public int getData() {
        return data;
    }

    public void setLeft(Node left) {
        this.left = left;
    }

    public Node getLeft() {
        return left;
    }

    public void setRight(Node right) {
        this.right = right;
    }

    public Node getRight() {
        return right;
    }
}

class BinaryTree {
    Node root = null;

    public void insert(int val) {
        root = insert(root, val);
    }

    private Node insert(Node node, int val) {
        Node newNode = new Node(val);

        if (node == null) {
            node = newNode;
        } else if (node.getLeft() == null) {
            node.setLeft(insert(node.getLeft(), val));
        } else if (node.getRight() == null) {
            node.setRight(insert(node.getRight(), val));
        } else {
            node.setLeft(insert(node.getLeft(), val));
        }

        return node;
    }

    public boolean search(int val) {
        return search(root, val);
    }

    public boolean search(Node node, int val) {
        if (node.getData() == val) {
            return true;
        } else {
            if (node.getLeft() != null && search(node.getLeft(), val))
                return true;
            else if (node.getRight() != null && search(node.getRight(), val))
                return true;
            else
                return false;
        }
    }

    public int count() {
        return countNodes(root);
    }

    public int countNodes(Node node) {
        if (node == null)
            return 0;
        else {
            int nodes = 1; // 1 for root node
            nodes += countNodes(node.getLeft());
            nodes += countNodes(node.getRight());
            return nodes;
        }
    }
}

public class BinaryTreeImpl {
    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();

        bt.insert(5);
        bt.insert(7);
        bt.insert(12);
        bt.insert(9);

        System.out.println(bt.count() + "");
    }
}
