class Node {
    constructor(value) {
        this.value = value;
        this.prev = null;
        this.next = null;
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
            // console.log("object");
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

const list = new DoublyLinkedList();
const listValues = [10, 8, 5, 7, 9, 1, 6, 4];

list.insertValues(listValues);

list.printList();

console.log(list.containsNodeWithValue(7));

let nodeToInsert = list.head;
let node = list.head;

while (nodeToInsert && nodeToInsert.value !== 9) {
    nodeToInsert = nodeToInsert.next;
}

while (node && node.value !== 5) {
    node = node.next;
}

list.insertBefore(node, nodeToInsert);

list.printList();
