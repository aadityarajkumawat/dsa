interface Node {
    data: number
    left: Node | null
    right: Node | null
    isLeaf: () => boolean
}

export function Node(
    data: number = 0,
    left: Node | null = null,
    right: Node | null = null,
) {
    const nodeAPI = {
        isLeaf: function (): boolean {
            return left === null && right === null
        },
    }

    return { data, left, right, ...nodeAPI }
}

export function isNull(node: Node | null) {
    return node === null
}
