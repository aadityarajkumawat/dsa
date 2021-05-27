class Node {
    constructor(value) {
        this.value = value;
        this.prev = null;
        this.next = null;
    }
}

class LinkedList {
    constructor() {
        this.head = null;
    }

    // O(1) time | O(1) space
    setHead(node) {
        if (!this.head) {
            this.insert(node);
            return;
        }

        node.next = this.head;
        this.head = node;
    }

    // O(n) time | O(1) space
    setTail(node) {
        this.insert(node);
    }

    // O(n) time | O(1) space
    printList(node) {
        let outputStr = "";

        while (node) {
            if (!node.next) {
                outputStr += node.value;
            } else {
                outputStr += node.value + " ➞ ";
            }
            node = node.next;
        }

        console.log(outputStr);
    }

    // O(n) time | O(1) space
    insert(node) {
        if (!this.head) {
            this.head = node;
            return;
        }

        let lastNode = this.head;

        while (lastNode.next) {
            lastNode = lastNode.next;
        }

        lastNode.next = node;

        return lastNode.next;
    }

    // O(n) time | O(1) space
    insertAfter(node, nodeToInsert) {
        if (nodeToInsert === this.head && !nodeToInsert.next) {
            return;
        }

        this.remove(nodeToInsert);

        if (!node.next) {
            this.setTail(nodeToInsert);
        } else {
            nodeToInsert.next = node.next;
            node.next = nodeToInsert;
        }
    }

    // O(n) time | O(1) space
    insertBefore(node, nodeToInsert) {
        if (nodeToInsert === this.head && !nodeToInsert.next) {
            return;
        }

        this.remove(nodeToInsert);

        if (node === this.head) {
            this.setHead(nodeToInsert);
        } else {
            let prevNode = this.head;

            while (prevNode.next !== node) {
                prevNode = prevNode.next;
            }

            prevNode.next = nodeToInsert;
            nodeToInsert.next = node;
        }
    }

    // O(p) time | O(1) space
    insertAtPosition(position, node) {
        if (position === 1) {
            this.setHead(node);
        }

        let currentPosition = 1;
        let currentNode = this.node;

        while (currentNode && currentPosition !== position) {
            currentNode = currentNode.next;
            currentPosition += 1;
        }

        if (currentNode) {
            this.insertBefore(currentNode, node);
        } else {
            this.setTail(node);
        }
    }

    // O(n^2) time | O(1) space
    removeNodesWithValue(value) {
        let node = this.head;

        while (node) {
            let nodeToRemove = node;
            node = node.next;

            if (value === nodeToRemove.value) {
                this.remove(nodeToRemove);
            }
        }
    }

    // O(n) time | O(1) space
    remove(node) {
        if (node === this.head) {
            this.head = this.head.next;
            node.next = null;
            return;
        }

        this.removeNodeBindings(node);
    }

    // O(n) time | O(1) space
    containsNodeWithValue(value) {
        let node = this.head;

        while (node && node.value !== value) {
            node = node.next;
        }

        return node !== null;
    }

    // O(n) time | O(1) space
    reverse() {
        let currentNode = this.head;
        let prev = null;
        let next = null;

        while (true) {
            if (!currentNode) break;

            next = currentNode.next;
            currentNode.next = prev;
            prev = currentNode;
            currentNode = next;
        }

        return prev;
    }

    removeNodeBindings(node) {
        if (!node.next) {
            let secondLast = this.head;

            while (secondLast.next.next) {
                secondLast = secondLast.next;
            }

            secondLast.next = null;
        } else {
            let prevNode = this.head;

            while (prevNode.next !== node) {
                prevNode = prevNode.next;
            }

            prevNode.next = node.next;
        }

        node.next = null;
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
    }

    // set the given node as head
    setHead(node) {
        if (!this.head) {
            this.head = node;
            this.tail = node;
            return;
        }

        this.insertBefore(this.head, node);
    }

    // set the given node as tail
    setTail(node) {
        if (!this.tail) {
            this.setHead(node);
            return;
        }

        this.insertAfter(this.tail, node);
    }

    insertBefore(node, nodeToInsert) {
        if (nodeToInsert === this.head && nodeToInsert === this.tail) {
            return;
        }

        this.remove(nodeToInsert);

        nodeToInsert.prev = node.prev;
        nodeToInsert.next = node;

        if (node.prev) {
            node.prev.next = nodeToInsert;
        } else {
            this.head = nodeToInsert;
        }
        node.prev = nodeToInsert;
    }

    insertAfter(node, nodeToInsert) {
        if (nodeToInsert === this.head && nodeToInsert === this.tail) {
            return;
        }

        this.remove(nodeToInsert);

        nodeToInsert.next = node.next;
        nodeToInsert.prev = node;

        if (node.next) {
            node.next.prev = nodeToInsert;
        } else {
            this.tail = nodeToInsert;
        }
        node.next = nodeToInsert;
    }

    insertAtPosition(position, nodeToInsert) {
        if (position === 1) {
            this.setHead(nodeToInsert);
        }

        let currentPosition = 1;
        let node = this.head;

        while (currentPosition !== position && node) {
            node = node.next;
            currentPosition += 1;
        }

        if (node) {
            this.insertBefore(node, nodeToInsert);
        } else {
            this.setTail(nodeToInsert);
        }
    }

    // remove all node with given value
    removeNodesWithValue(value) {
        let node = this.head;

        while (node) {
            let nodeToRemove = node;
            node = node.next;
            if (nodeToRemove.value === value) {
                this.remove(nodeToRemove);
            }
        }
    }

    // remove the given particular node
    remove(node) {
        if (node === this.head) {
            this.head = node.next;
        }
        if (node === this.tail) {
            this.tail = node.prev;
        }

        this.removeNodeBindings(node);
    }

    // checks if the given value is present in list
    containsNodeWithValue(value) {
        let node = this.head;

        while (node && node.value !== value) {
            node = node.next;
        }

        return node !== null;
    }

    removeNodeBindings(node) {
        if (node.next) {
            node.next.prev = node.prev;
        }
        if (node.prev) {
            node.prev.next = node.next;
        }

        node.next = null;
        node.prev = null;
    }

    printList() {
        let node = this.head;
        let outputStr = "";
        while (node !== null) {
            if (node.next === null) {
                outputStr += node.value;
            } else {
                outputStr += node.value + " ⇆ ";
            }
            node = node.next;
        }

        console.log(outputStr);
    }

    insertValues(array) {
        let prev = null;

        for (let num of array) {
            let node = new Node(num);
            if (!this.head) {
                this.setHead(node);
                prev = node;
            } else {
                this.insertAfter(prev, node);
                prev = node;
            }
        }
    }
}

const list = new LinkedList();
const listValues = [10, 8, 5, 7, 9, 1, 6, 4];

for (const num of listValues) {
    list.insert(new Node(num));
}

// console.log(list.containsNodeWithValue(7));
// console.log(list.containsNodeWithValue(11));

list.printList(list.head);
list.printList(list.reverse());

// list.insertBefore(list.head.next.next.next, list.head.next);
