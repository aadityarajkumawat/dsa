def find_closest_value(node, closest, current=999):
    if node is None:
        return closest

    if abs(node.data - closest) < abs(current - closest):
        closest = abs(node.data - closest)

    return closest
