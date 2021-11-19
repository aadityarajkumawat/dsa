package tree;

class BNode {
    protected int data;
    protected BNode left;
    protected BNode right;

    BNode(int data) {
        this.data = data;
        this.left = null;
        this.right = null;
    }

    BNode(int data, BNode left, BNode right) {
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

    public void setLeft(BNode left) {
        this.left = left;
    }

    public BNode getLeft() {
        return left;
    }

    public void setRight(BNode right) {
        this.right = right;
    }

    public BNode getRight() {
        return right;
    }
}
