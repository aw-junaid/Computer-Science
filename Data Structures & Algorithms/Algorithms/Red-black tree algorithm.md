**Red-Black Tree**

Red-Black Tree is a self-balancing binary search tree data structure. It maintains balance by enforcing five properties that ensure the tree remains approximately balanced during insertion and deletion operations. The properties of a Red-Black Tree are:

1. Every node is either red or black.
2. The root and leaves (null nodes) are black.
3. Red nodes cannot have red children.
4. Every path from a node to its descendant leaves has the same black height.
5. The height of a Red-Black Tree is guaranteed to be at most 2*log(n + 1), where n is the number of nodes in the tree.

The main advantage of Red-Black Trees over simple binary search trees is that the worst-case height of a Red-Black Tree is guaranteed to be O(log n), making search, insert, and delete operations efficient.

**Working of Red-Black Tree**

The Red-Black Tree maintains its balance by performing color adjustments and rotations during insertions and deletions. Here's a brief overview of how these operations work:

**Insertion:**
1. Perform a standard BST insertion with the new node colored red.
2. Fix the tree to maintain Red-Black properties by performing rotations and recoloring as necessary.

**Deletion:**
1. Perform a standard BST deletion and adjust the colors of the nodes affected by the deletion.
2. If the node deleted or replaced was black, apply fix-up to rebalance the tree.

The rotations (left and right) are used to adjust the structure of the tree while maintaining the Red-Black properties.

**Examples where Red-Black Trees are used:**
Red-Black Trees are widely used in various applications where a balanced binary search tree is required. Some common use cases include:

1. Associative Containers: Red-Black Trees are used to implement associative containers like C++ `std::map` and `std::set`.
2. Linux Scheduler: The Completely Fair Scheduler in the Linux kernel uses Red-Black Trees to efficiently manage process scheduling.
3. Interval Trees: Red-Black Trees can be used to implement interval trees for efficiently storing and querying intervals.
4. Memory Allocation: Red-Black Trees can be used in memory allocation algorithms to efficiently manage free memory blocks.

**Python implementation of Red-Black Tree**

```python
class Node:
    def __init__(self, key, color, left=None, right=None, parent=None):
        self.key = key
        self.color = color
        self.left = left
        self.right = right
        self.parent = parent

class RedBlackTree:
    def __init__(self):
        self.NIL_LEAF = Node(None, "black")
        self.root = self.NIL_LEAF

    def left_rotate(self, node):
        right_child = node.right
        node.right = right_child.left

        if right_child.left != self.NIL_LEAF:
            right_child.left.parent = node

        right_child.parent = node.parent

        if node.parent is None:
            self.root = right_child
        elif node == node.parent.left:
            node.parent.left = right_child
        else:
            node.parent.right = right_child

        right_child.left = node
        node.parent = right_child

    def right_rotate(self, node):
        left_child = node.left
        node.left = left_child.right

        if left_child.right != self.NIL_LEAF:
            left_child.right.parent = node

        left_child.parent = node.parent

        if node.parent is None:
            self.root = left_child
        elif node == node.parent.right:
            node.parent.right = left_child
        else:
            node.parent.left = left_child

        left_child.right = node
        node.parent = left_child

    def insert(self, key):
        new_node = Node(key, "red")
        parent = None
        current = self.root

        while current != self.NIL_LEAF:
            parent = current
            if key < current.key:
                current = current.left
            else:
                current = current.right

        new_node.parent = parent

        if parent is None:
            self.root = new_node
        elif key < parent.key:
            parent.left = new_node
        else:
            parent.right = new_node

        self._fix_insert(new_node)

    def _fix_insert(self, node):
        while node.parent.color == "red":
            if node.parent == node.parent.parent.left:
                uncle = node.parent.parent.right
                if uncle.color == "red":
                    node.parent.color = "black"
                    uncle.color = "black"
                    node.parent.parent.color = "red"
                    node = node.parent.parent
                else:
                    if node == node.parent.right:
                        node = node.parent
                        self.left_rotate(node)
                    node.parent.color = "black"
                    node.parent.parent.color = "red"
                    self.right_rotate(node.parent.parent)
            else:
                uncle = node.parent.parent.left
                if uncle.color == "red":
                    node.parent.color = "black"
                    uncle.color = "black"
                    node.parent.parent.color = "red"
                    node = node.parent.parent
                else:
                    if node == node.parent.left:
                        node = node.parent
                        self.right_rotate(node)
                    node.parent.color = "black"
                    node.parent.parent.color = "red"
                    self.left_rotate(node.parent.parent)

        self.root.color = "black"

    def inorder_traversal(self, node):
        if node != self.NIL_LEAF:
            self.inorder_traversal(node.left)
            print(node.key, end=" ")
            self.inorder_traversal(node.right)

if __name__ == "__main__":
    rb_tree = RedBlackTree()
    keys = [55, 40, 65, 60, 75, 57, 58, 25, 33]

    for key in keys:
        rb_tree.insert(key)

    print("Inorder Traversal of Red-Black Tree:")
    rb_tree.inorder_traversal(rb_tree.root)
```

**C++ implementation of Red-Black Tree**

```cpp
#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int key;
    Color color;
    Node* left;
    Node* right;
    Node* parent;

    Node(int key) : key(key), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
    Node* root;
    Node* NIL_LEAF;

    void left_rotate(Node* node);
    void right_rotate(Node* node);
    void fix_insert(Node* node);

public:
    RedBlackTree();
    void insert(int key);
    void inorder_traversal(Node* node);
};

RedBlackTree::RedBlackTree() {
    NIL_LEAF = new Node(-1);
    NIL_LEAF->color = BLACK;
    root = NIL_LEAF;
}

void RedBlackTree::left_rotate(Node* node) {
    Node* right_child = node->right;
    node->right = right_child->left;

    if (right_child->left != NIL_LEAF) {
        right_child->left->parent = node;
    }

    right_child->parent = node->parent;

    if (node->parent == nullptr) {
        root = right_child;
    } else if (node == node->parent->left) {
        node->parent->left = right_child;
    } else {


        node->parent->right = right_child;
    }

    right_child->left = node;
    node->parent = right_child;
}

void RedBlackTree::right_rotate(Node* node) {
    Node* left_child = node->left;
    node->left = left_child->right;

    if (left_child->right != NIL_LEAF) {
        left_child->right->parent = node;
    }

    left_child->parent = node->parent;

    if (node->parent == nullptr) {
        root = left_child;
    } else if (node == node->parent->right) {
        node->parent->right = left_child;
    } else {
        node->parent->left = left_child;
    }

    left_child->right = node;
    node->parent = left_child;
}

void RedBlackTree::fix_insert(Node* node) {
    while (node->parent && node->parent->color == RED) {
        if (node->parent == node->parent->parent->left) {
            Node* uncle = node->parent->parent->right;
            if (uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->right) {
                    node = node->parent;
                    left_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                right_rotate(node->parent->parent);
            }
        } else {
            Node* uncle = node->parent->parent->left;
            if (uncle && uncle->color == RED) {
                node->parent->color = BLACK;
                uncle->color = BLACK;
                node->parent->parent->color = RED;
                node = node->parent->parent;
            } else {
                if (node == node->parent->left) {
                    node = node->parent;
                    right_rotate(node);
                }
                node->parent->color = BLACK;
                node->parent->parent->color = RED;
                left_rotate(node->parent->parent);
            }
        }
    }
    root->color = BLACK;
}

void RedBlackTree::insert(int key) {
    Node* new_node = new Node(key);
    Node* parent = nullptr;
    Node* current = root;

    while (current != NIL_LEAF) {
        parent = current;
        if (key < current->key) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    new_node->parent = parent;

    if (parent == nullptr) {
        root = new_node;
    } else if (key < parent->key) {
        parent->left = new_node;
    } else {
        parent->right = new_node;
    }

    fix_insert(new_node);
}

void RedBlackTree::inorder_traversal(Node* node) {
    if (node != NIL_LEAF) {
        inorder_traversal(node->left);
        std::cout << node->key << " ";
        inorder_traversal(node->right);
    }
}

int main() {
    RedBlackTree rb_tree;
    int keys[] = {55, 40, 65, 60, 75, 57, 58, 25, 33};
    int num_keys = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < num_keys; i++) {
        rb_tree.insert(keys[i]);
    }

    std::cout << "Inorder Traversal of Red-Black Tree: ";
    rb_tree.inorder_traversal(rb_tree.root);

    return 0;
}
```

We covered the working principles of Red-Black Trees, their use cases, and provided Python and C++ implementations of the Red-Black Tree data structure. Red-Black Trees are widely used in various applications that require a self-balancing binary search tree to ensure efficient operations while maintaining balance.
