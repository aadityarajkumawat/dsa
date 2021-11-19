const { BST } = require("../bst-construction/bst-construction");

function helper0(tree, target, closest) {
    if (!tree) return closest;

    if (Math.abs(target - closest) > Math.abs(target - tree.value)) {
        closest = tree.value;
    }

    if (target < tree.value) {
        return helper0(tree.left, target, closest);
    } else if (target > tree.value) {
        return helper0(tree.right, target, closest);
    } else return closest;
}

function findClosestValueInBstV0(tree, target) {
    return helper0(tree, target, Infinity);
}

const root = new BST(10);
root.insert(8).insert(7).insert(6).insert(11).insert(9).insert(16);

const closestV0 = findClosestValueInBstV0(root, 15);
const closestV1 = findClosestValueInBstV1(root, 15);

console.log(closestV0, closestV1);
