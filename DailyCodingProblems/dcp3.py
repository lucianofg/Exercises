# Given the root to a binary tree, implement serialize(root), which
# serializes the tree into a string; and deserialize(s), which
# deserializes the string back into a tree

class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

def serialize(root):
    def s(root):
        if root is None:
            return 'None '

        serialized_tree = str(root.val) + ' '
        serialized_tree += s(root.left)
        serialized_tree += s(root.right)
        return serialized_tree

    serialized_tree = s(root)
    return serialized_tree.strip()

def deserialize(tree):
    def ds(nodes):
        if len(nodes) == 0:
            return
        if nodes[0] == 'None':
            val = None
        else:
            val = nodes[0]
        nodes.remove(nodes[0])
        left = ds(nodes)
        right = ds(nodes)
        return Node(val, left, right)

    splitted_tree = tree.split(' ')
    return ds(splitted_tree)

# The following test should pass
node = Node('root', Node('left', Node('left.left')), Node('right'))
assert deserialize(serialize(node)).left.left.val == 'left.left'

