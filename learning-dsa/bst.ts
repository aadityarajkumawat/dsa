import { isNull, Node } from './node'

function Tree(rootValue: number | null = null) {
    let root = rootValue ? Node(rootValue) : null

    const treeAPI = {
        inorder: function (node = root) {
            recursiveCaller(node)

            function recursiveCaller(node: null | typeof root) {
                if (isNull(node)) return

                recursiveCaller(node.left)
                console.log(node.data)
                recursiveCaller(node.right)
            }
        },
        insertIteratively: function (value: number) {
            if (isNull(root)) {
                root = Node(value)
                return
            }

            let currentNode = root

            while (currentNode) {
                if (value >= currentNode.data) {
                    if (isNull(currentNode.right)) {
                        currentNode.right = Node(value)
                        return
                    }

                    currentNode = currentNode.right
                } else {
                    if (isNull(currentNode.left)) {
                        currentNode.left = Node(value)
                        return
                    }

                    currentNode = currentNode.left
                }
            }
        },
        search: function (value: number) {},
        delete: function (value: number) {},
    }

    return treeAPI
}

const tree = Tree()

tree.insertIteratively(4)
tree.insertIteratively(8)
tree.insertIteratively(2)
tree.insertIteratively(1)
tree.insertIteratively(5)

tree.inorder()
