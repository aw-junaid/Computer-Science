**Splay Tree**

A Splay Tree is a self-adjusting binary search tree data structure that performs "splaying" operations on the tree during insertion, deletion, or search to bring the accessed node to the root. The splaying operation involves a series of rotations and restructuring to keep the frequently accessed nodes closer to the root, which helps improve the overall efficiency of the tree.

**Working of Splay Tree**

The key idea behind the Splay Tree is to maintain a property called "access property." When a node is accessed (found, inserted, or deleted), it is moved to the root of the tree using a series of rotations called "splaying" to ensure that frequently accessed nodes are closer to the root.

The splaying operation involves three types of rotations: Zig, Zig-Zig, and Zig-Zag.

1. **Zig:** In a Zig operation, the accessed node is a child of the root, and a single rotation is performed to move it to the root position.

2. **Zig-Zig:** In a Zig-Zig operation, both the accessed node and its parent are children of the root. Two consecutive rotations are performed to move both nodes to the root position.

3. **Zig-Zag:** In a Zig-Zag operation, the accessed node is a child of the root, but its parent is not. Two consecutive rotations are performed to move the accessed node to the root while preserving the order of the nodes.

**Insertion in Splay Tree:**
1. Perform a standard BST insertion to find the position of the new node in the tree.
2. Splay the newly inserted node to the root to maintain the access property.

**Search in Splay Tree:**
1. Perform a standard BST search to find the target node.
2. Splay the target node to the root to maintain the access property.

**Deletion in Splay Tree:**
1. Perform a standard BST deletion to remove the target node from the tree.
2. Splay the parent of the deleted node (or its replacement) to the root to maintain the access property.

**Examples where Splay Trees are used:**
Splay Trees are used in various applications where frequently accessed items need to be quickly accessed in a self-adjusting manner. Some common use cases include:

1. Caches: Splay Trees are used in cache implementations to maintain frequently accessed data closer to the root for quicker retrieval.

2. Dynamic Optimizations: Splay Trees are used in dynamic programming algorithms to maintain optimal solutions for subproblems.

3. Implementing Associative Containers: Splay Trees can be used to implement associative containers like C++ `std::map` and `std::set`.

**Python implementation of Splay Tree:**

```python
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class SplayTree:
    def __init__(self):
        self.root = None

    def left_rotate(self, x):
        y = x.right
        x.right = y.left
        y.left = x
        return y

    def right_rotate(self, x):
        y = x.left
        x.left = y.right
        y.right = x
        return y

    def splay(self, key):
        if not self.root:
            return None

        dummy = Node(None)
        left_tree = dummy_left = Node(None)
        right_tree = dummy_right = Node(None)

        current = self.root
        while current:
            if key < current.key:
                if not current.left:
                    break
                if key < current.left.key:
                    current = self.right_rotate(current)
                    if not current.left:
                        break
                right_tree.left = current
                right_tree = right_tree.left
                current = current.left
                right_tree.left = None
            elif key > current.key:
                if not current.right:
                    break
                if key > current.right.key:
                    current = self.left_rotate(current)
                    if not current.right:
                        break
                left_tree.right = current
                left_tree = left_tree.right
                current = current.right
                left_tree.right = None
            else:
                break

        left_tree.right = current.left
        right_tree.left = current.right
        current.left = dummy_right.right
        current.right = dummy_left.left
        self.root = current

    def insert(self, key):
        if not self.root:
            self.root = Node(key)
        else:
            self.splay(key)
            if key < self.root.key:
                new_node = Node(key)
                new_node.left = self.root.left
                new_node.right = self.root
                self.root.left = None
                self.root = new_node
            elif key > self.root.key:
                new_node = Node(key)
                new_node.right = self.root.right
                new_node.left = self.root
                self.root.right = None
                self.root = new_node

    def search(self, key):
        if not self.root:
            return False

        self.splay(key)
        return self.root.key == key

    def inorder_traversal(self, node):
        if node:
            self.inorder_traversal(node.left)
            print(node.key, end=" ")
            self.inorder_traversal(node.right)

if __name__ == "__main__":
    splay_tree = SplayTree()
    keys = [55, 40, 65, 60, 75, 57, 58, 25, 33]

    for key in keys:
        splay_tree.insert(key)

    print("Inorder Traversal of Splay Tree:")
    splay_tree.inorder_traversal(splay_tree.root)
```

**C++ implementation of Splay Tree:**

```cpp
#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;

    Node(int key) : key(key), left(nullptr), right(nullptr) {}
};

class SplayTree {
private:
    Node* root;

    Node* left_rotate(Node* x);
    Node* right_rotate(Node* x);
    void splay(int key);

public:
    SplayTree();
    void insert(int key);
    bool search(int key);
    void inorder_traversal(Node* node);
};

SplayTree::SplayTree() : root(nullptr) {}

Node* SplayTree::left_rotate(Node* x) {
    Node* y = x->right;
    x->right = y->left;
    y->left = x;
    return y;
}

Node* SplayTree::right_rotate(Node* x) {
    Node* y = x->left;
    x->left = y->right;
    y->right = x;
    return y;
}

void SplayTree::splay(int key) {
    if (!root) {
        return;
    }

    Node dummy_left(0);
    Node dummy_right(0);
    Node* left_tree = &dummy_left;
    Node* right_tree = &dummy_right;

    Node* current = root;
    while (current) {
        if (key < current->key) {
            if (!current->left) {
                break;
            }
            if (key < current->left->key) {
                current = right_rotate(current);
                if (!current->left) {
                    break;
                }
            }
            right_tree->left = current;
            right

_tree = right_tree->left;
            current = current->left;
            right_tree->left = nullptr;
        } else if (key > current->key) {
            if (!current->right) {
                break;
            }
            if (key > current->right->key) {
                current = left_rotate(current);
                if (!current->right) {
                    break;
                }
            }
            left_tree->right = current;
            left_tree = left_tree->right;
            current = current->right;
            left_tree->right = nullptr;
        } else {
            break;
        }
    }

    left_tree->right = current->left;
    right_tree->left = current->right;
    current->left = dummy_right.right;
    current->right = dummy_left.left;
    root = current;
}

void SplayTree::insert(int key) {
    if (!root) {
        root = new Node(key);
    } else {
        splay(key);
        if (key < root->key) {
            Node* new_node = new Node(key);
            new_node->left = root->left;
            new_node->right = root;
            root->left = nullptr;
            root = new_node;
        } else if (key > root->key) {
            Node* new_node = new Node(key);
            new_node->right = root->right;
            new_node->left = root;
            root->right = nullptr;
            root = new_node;
        }
    }
}

bool SplayTree::search(int key) {
    if (!root) {
        return false;
    }

    splay(key);
    return root->key == key;
}

void SplayTree::inorder_traversal(Node* node) {
    if (node) {
        inorder_traversal(node->left);
        std::cout << node->key << " ";
        inorder_traversal(node->right);
    }
}

int main() {
    SplayTree splay_tree;
    int keys[] = {55, 40, 65, 60, 75, 57, 58, 25, 33};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < num_keys; i++) {
        splay_tree.insert(keys[i]);
    }

    std::cout << "Inorder Traversal of Splay Tree: ";
    splay_tree.inorder_traversal(splay_tree.root);

    return 0;
}
```

In this article, we covered the working principles of Splay Trees, their use cases, and provided Python and C++ implementations of the Splay Tree data structure. Splay Trees are self-adjusting binary search trees that optimize frequently accessed nodes to the root, making them efficient for access operations.
