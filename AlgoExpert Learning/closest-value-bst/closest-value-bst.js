const { BST } = require('../bst-construction/bst-construction');

function findClosestValueInBstV0(tree, target) {
    return findClosestValueInBstHelperV0(tree, target, Infinity);
}

function findClosestValueInBstHelperV0(tree, target, closest) {
    if (!tree) {
        return closest;
    }

    if (Math.abs(target - tree.value) < Math.abs(target - closest)) {
        closest = tree.value;
    }

    if (target < tree.value) {
        return findClosestValueInBstHelperV0(tree.left, target, closest);
    } else if (target > tree.value) {
        return findClosestValueInBstHelperV0(tree.right, target, closest);
    } else {
        return closest;
    }
}

function findClosestValueInBstV1(tree, target) {
    return findClosestValueInBstHelperV1(tree, target, Infinity);
}

function findClosestValueInBstHelperV1(tree, target, closest) {
    let currentNode = tree;

    while (currentNode) {
        if (Math.abs(target - currentNode.value) < Math.abs(target - closest)) {
            closest = currentNode.value;
        }

        if (target < currentNode.value) {
            currentNode = currentNode.left;
        } else if (target > currentNode.value) {
            currentNode = currentNode.right;
        } else {
            break;
        }
    }

    return closest;
}

const root = new BST(10);
root.insert(8).insert(7).insert(6).insert(11).insert(9).insert(16);

const closestV0 = findClosestValueInBstV0(root, 15);
const closestV1 = findClosestValueInBstV1(root, 15);

console.log(closestV0, closestV1);
