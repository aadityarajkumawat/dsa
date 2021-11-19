package tree;

class BinaryTree {
    BNode root = null;

    public void insert(int val) {
        root = insert(root, val);
    }

    private BNode insert(BNode node, int val) {
        BNode newNode = new BNode(val);

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

    public boolean search(BNode node, int val) {
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

    public int countNodes(BNode node) {
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
