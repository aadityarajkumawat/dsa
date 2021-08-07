const { root } = require("../bst-construction/bst-construction");

function branchSums(tree) {
    let sums = [];
    calculateBranchSums(tree, 0, sums);

    return sums;
}

function calculateBranchSums(tree, runningSum, sums) {
    if (!tree) return;

    let newRunningSum = runningSum + tree.value;

    if (!tree.left && !tree.right) sums.push(newRunningSum);

    calculateBranchSums(tree.left, newRunningSum, sums);
    calculateBranchSums(tree.right, newRunningSum, sums);
}

console.log(branchSums(root));
