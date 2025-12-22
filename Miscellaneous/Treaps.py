import random

class Node:
    def __init__(self, key):
        self.key = key
        self.priority = random.randint(1, 100)
        self.left = None
        self.right = None

def rotate_right(node):
    x = node.left
    y = x.right
    x.right = node
    node.left = y
    return x

def rotate_left(node):
    x = node.right
    y = x.left
    x.left = node
    node.right = y
    return x

def insert(root, key):
    if root is None:
        return Node(key)
    if key < root.key:
        root.left = insert(root.left, key)
        if root.left and root.left.priority > root.priority:
            root = rotate_right(root)

    elif key > root.key:
        root.right = insert(root.right, key)
        if root.right and root.right.priority > root.priority:
            root = rotate_left(root)
    return root

def search(root, key):
    if root is None:
        return False
    if root.key == key:
        return True
    elif key < root.key:
        return search(root.left, key)
    else:
        return search(root.right, key)

def inorder(root):
    if root:
        inorder(root.left)
        print(f"(Key: {root.key}, Prio: {root.priority})", end=" -> ")
        inorder(root.right)

# --- Example Usage ---
if __name__ == "__main__":
    root = None
    keys = [20, 15, 5, 50, 30, 40]
    
    print("Inserting keys:", keys)
    for k in keys:
        root = insert(root, k)

    print("\nInorder Traversal (Sorted by Key):")
    inorder(root)
    print("End")