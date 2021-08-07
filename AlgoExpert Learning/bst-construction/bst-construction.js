class BST {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }

    insert(value) {
        let currentNode = this;

        while (true) {
            if (value < currentNode.value) {
                if (currentNode.left !== null) {
                    currentNode = currentNode.left;
                } else {
                    currentNode.left = new BST(value);
                    break;
                }
            } else {
                if (currentNode.right !== null) {
                    currentNode = currentNode.right;
                } else {
                    currentNode.right = new BST(value);
                    break;
                }
            }
        }

        return this;
    }

    contains(value) {
        let currentNode = this;

        while (currentNode !== null) {
            if (value < currentNode.value) {
                currentNode = currentNode.left;
            } else if (value > currentNode.value) {
                currentNode = currentNode.right;
            } else {
                return true;
            }
        }

        return false;
    }

    remove(value, parentNode = null) {
        let currentNode = this;

        while (currentNode !== null) {
            if (value < currentNode.value) {
                parentNode = currentNode;
                currentNode = currentNode.left;
            } else if (value > currentNode.value) {
                parentNode = currentNode;
                currentNode = currentNode.right;
            } else {
                if (currentNode.left !== null && currentNode.right !== null) {
                    currentNode.value = currentNode.right.getMinValue();
                    currentNode.right.remove(currentNode.value, currentNode);
                } else if (parentNode === null) {
                    if (currentNode.left !== null) {
                        currentNode.value = currentNode.left.value;
                        currentNode.right = currentNode.left.right;
                        currentNode.left = currentNode.left.left;
                    } else if (currentNode.right !== null) {
                        currentNode.value = currentNode.right.value;
                        currentNode.left = currentNode.right.left;
                        currentNode.right = currentNode.right.right;
                    } else {
                        currentNode.value = null;
                    }
                } else if (parentNode.left === currentNode) {
                    if (currentNode.left !== null) {
                        parentNode.left = currentNode.left;
                    } else {
                        parentNode.left = currentNode.right;
                    }
                } else if (parentNode.right === currentNode) {
                    if (currentNode.left !== null) {
                        parentNode.right = currentNode.left;
                    } else {
                        parentNode.right = currentNode.right;
                    }
                }

                break;
            }
        }

        return this;
    }

    getMinValue() {
        let currentNode = this;

        while (currentNode.left !== null) {
            currentNode = currentNode.left;
        }

        return currentNode.value;
    }

    printBST() {
        let currentNode = this;

        if (currentNode.left) {
            currentNode.left.printBST();
        }
        console.log(currentNode.value);
        if (currentNode.right) {
            currentNode.right.printBST();
        }
    }
}

const root = new BST(10);

root.insert(8).insert(7).insert(6).insert(11).insert(9).insert(16);

module.exports = { BST, root };

/**
        10
       /  \
      8    11
     / \    \
    7   9    16
   /
  6
*/

// root.printBST();
// console.log(root.contains(4));

// root.remove(8).remove(7).remove(6);
// root.printBST();
