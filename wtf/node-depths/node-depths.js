function findNodeDepthV0(root) {
    let sumOfDepths = 0;
    let stack = [{ node: root, depth: 0 }];
    while (stack.length > 0) {
        const nodeInfo = stack.pop();
        const { node, depth } = nodeInfo;
        if (!node) continue;
        sumOfDepths += depth;
        stack.push({ node: node.left, depth: depth + 1 });
        stack.push({ node: node.right, depth: depth + 1 });
    }
    return sumOfDepths;
}

function findNodeDepthV1(tree, depth = 0) {
    if (!tree) return 0;
    return (
        depth +
        findNodeDepthV1(tree.left, depth + 1) +
        findNodeDepthV1(tree.right, depth + 1)
    );
}
