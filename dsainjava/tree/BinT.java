package tree;

public class BinT {
    public static void main(String[] args) {
        BNode node = new BNode(6);
        BNode left = new BNode(5);
        BNode right = new BNode(7);

        node.left = left;
        node.right = right;

        System.out.println("node.data: " + node.data);
        System.out.println("node.left.data: " + node.left.data);
        System.out.println("node.right.data: " + node.right.data);
    }
}
