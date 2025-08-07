class Node:
    def __init__(self, key): 
        self.key = key
        self.left = None
        self.right = None
        self.height = 1

class AVLTree:
    def get_height(self, node):
        if not node:
            return 0
        return node.height

    def get_balance(self, node):
        if not node:
            return 0
        return self.get_height(node.left) - self.get_height(node.right)

    # Right Rotate
    def right_rotate(self, z):  
        y = z.left
        T3 = y.right

        y.right = z
        z.left = T3

        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        return y

    # Left Rotate
    def left_rotate(self, z):  
        y = z.right
        T2 = y.left

        y.left = z
        z.right = T2

        z.height = 1 + max(self.get_height(z.left), self.get_height(z.right))
        y.height = 1 + max(self.get_height(y.left), self.get_height(y.right))

        return y

    def insert(self, root, key):
        if not root:
            return Node(key)
        elif key < root.key:
            root.left = self.insert(root.left, key)
        elif key > root.key:
            root.right = self.insert(root.right, key)
        else:
            return root

        root.height = 1 + max(self.get_height(root.left), self.get_height(root.right))
        balance = self.get_balance(root)

       
        if balance > 1 and key < root.left.key:
            return self.right_rotate(root)

        if balance < -1 and key > root.right.key:
            return self.left_rotate(root)

        if balance > 1 and key > root.left.key:
            root.left = self.left_rotate(root.left)
            return self.right_rotate(root)

        if balance < -1 and key < root.right.key:
            root.right = self.right_rotate(root.right)
            return self.left_rotate(root)

        return root
# DLR
    def preorder(self, root):
        if not root:
            return
        print(root.key, end=' ')
        self.preorder(root.left)
        self.preorder(root.right)

# LRD
    def postorder(self, root):
        if not root:
            return
        self.postorder(root.left)
        self.postorder(root.right)
        print(root.key, end=' ')
        
 # LDR
    def inorder(self, root):
        if not root:
            return
        self.inorder(root.left)
        print(root.key, end=' ')  
        self.inorder(root.right)
       


avl = AVLTree()
root = None

values = [10, 20, 30, 40, 50, 25, 35, 15]
for val in values:
    root = avl.insert(root, val)

print("Preorder Traversal of AVL Tree:\n")
avl.preorder(root)
print("\n")

print("inorder Traversal of AVL Tree:\n")
avl.inorder(root)
print("\n")

print("Postorder Traversal of AVL Tree:\n")
avl.postorder(root)
print("\n")
