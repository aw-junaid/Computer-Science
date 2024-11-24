### **Binary Tree**

A **Binary Tree** is a hierarchical data structure where each node has at most **two children**, commonly referred to as the **left child** and the **right child**. It is one of the simplest and most widely used tree structures in computer science. Binary trees have many applications in data storage, searching, sorting, and more.

---

### **Basic Terminology of a Binary Tree**

1. **Node**: A unit in the tree containing data and links (pointers) to its children.
2. **Root**: The topmost node of the binary tree. It has no parent.
3. **Parent**: A node that has one or more child nodes.
4. **Child**: A node that is a descendant of another node.
5. **Leaf**: A node that has no children (end node).
6. **Subtree**: A tree formed by a node and all of its descendants.
7. **Level**: The level of a node is defined by the number of edges from the root to the node. The root is at level 0, its children are at level 1, and so on.
8. **Depth**: The depth of a node is the number of edges from the root to the node.
9. **Height**: The height of a node is the longest path from that node to a leaf. The height of the tree is the height of the root node.
10. **Edge**: A connection between two nodes.

---

### **Properties of Binary Tree**

- **At most two children**: Each node can have zero, one, or two children.
- **Binary tree height**: The height of a binary tree is the maximum number of edges from the root to the leaf node. A **balanced binary tree** has a height of **O(log n)**, making operations faster.
- **Number of nodes**: A binary tree with `n` nodes has a maximum of `2^h - 1` nodes at height `h`. For a complete binary tree, the nodes are filled at every level except possibly the last one.

---

### **Types of Binary Trees**

1. **Full Binary Tree**:
   - A binary tree where every node has either 0 or 2 children. In other words, all non-leaf nodes must have exactly two children.

2. **Perfect Binary Tree**:
   - A binary tree where all internal nodes have exactly two children and all leaf nodes are at the same level. In a perfect binary tree, the total number of nodes is `2^(h+1) - 1`, where `h` is the height of the tree.

3. **Complete Binary Tree**:
   - A binary tree in which all levels are completely filled except possibly for the last level, which is filled from left to right.

4. **Degenerate (or Pathological) Tree**:
   - A binary tree in which every parent node has only one child, making the tree essentially a linked list.

5. **Balanced Binary Tree**:
   - A binary tree in which the height of the left and right subtrees of any node differ by at most one. This ensures operations like search, insertion, and deletion are performed in logarithmic time.

---

### **Operations in a Binary Tree**

1. **Insertion**:
   - Inserting a new node in a binary tree usually involves finding an appropriate location for the new node. In a **complete binary tree**, insertion typically happens at the next available position on the last level.

2. **Searching**:
   - Searching for an element in a binary tree is generally done by starting at the root and recursively traversing the left or right child depending on the value being searched.

3. **Deletion**:
   - Deleting a node in a binary tree may involve replacing the node with a leaf node, and potentially re-arranging the tree structure to maintain its properties.

4. **Traversal**:
   - A **traversal** involves visiting all the nodes of the tree in a specific order. There are several traversal techniques, which we'll cover below.

---

### **Binary Tree Traversals**

Traversal of a binary tree involves visiting each node exactly once. There are several types of tree traversal methods:

#### **1. In-order Traversal**
- **Process**: Visit the left subtree, then the node, and then the right subtree.
- **Usage**: In-order traversal of a **binary search tree** produces a sorted sequence of nodes.

```cpp
void inorder(Node* root) {
    if (root != nullptr) {
        inorder(root->left);  // Visit left child
        cout << root->data << " ";  // Visit node
        inorder(root->right);  // Visit right child
    }
}
```

#### **2. Pre-order Traversal**
- **Process**: Visit the node, then the left subtree, and then the right subtree.
- **Usage**: Pre-order traversal is useful for creating a copy of the tree or evaluating expressions.

```cpp
void preorder(Node* root) {
    if (root != nullptr) {
        cout << root->data << " ";  // Visit node
        preorder(root->left);  // Visit left child
        preorder(root->right);  // Visit right child
    }
}
```

#### **3. Post-order Traversal**
- **Process**: Visit the left subtree, then the right subtree, and then the node.
- **Usage**: Post-order traversal is often used for deleting nodes in a tree or evaluating postfix expressions.

```cpp
void postorder(Node* root) {
    if (root != nullptr) {
        postorder(root->left);  // Visit left child
        postorder(root->right);  // Visit right child
        cout << root->data << " ";  // Visit node
    }
}
```

#### **4. Level-order Traversal**
- **Process**: Visit nodes level by level, from top to bottom and left to right.
- **Usage**: It’s usually implemented using a **queue** and is particularly useful for searching or finding the shortest path.

```cpp
void levelOrder(Node* root) {
    if (root == nullptr) return;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->data << " ";
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
}
```

---

### **Example of Binary Tree in C++**

```cpp
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BinaryTree {
public:
    Node* root;

    BinaryTree() {
        root = nullptr;
    }

    // In-order traversal
    void inorder(Node* node) {
        if (node != nullptr) {
            inorder(node->left);
            cout << node->data << " ";
            inorder(node->right);
        }
    }

    // Pre-order traversal
    void preorder(Node* node) {
        if (node != nullptr) {
            cout << node->data << " ";
            preorder(node->left);
            preorder(node->right);
        }
    }

    // Post-order traversal
    void postorder(Node* node) {
        if (node != nullptr) {
            postorder(node->left);
            postorder(node->right);
            cout << node->data << " ";
        }
    }
};

int main() {
    BinaryTree tree;
    tree.root = new Node(1);
    tree.root->left = new Node(2);
    tree.root->right = new Node(3);
    tree.root->left->left = new Node(4);
    tree.root->left->right = new Node(5);
    tree.root->right->left = new Node(6);
    tree.root->right->right = new Node(7);

    // In-order traversal
    cout << "In-order traversal: ";
    tree.inorder(tree.root);
    cout << endl;

    // Pre-order traversal
    cout << "Pre-order traversal: ";
    tree.preorder(tree.root);
    cout << endl;

    // Post-order traversal
    cout << "Post-order traversal: ";
    tree.postorder(tree.root);
    cout << endl;

    return 0;
}
```

**Output**:
```
In-order traversal: 4 2 5 1 6 3 7 
Pre-order traversal: 1 2 4 5 3 6 7 
Post-order traversal: 4 5 2 6 7 3 1 
```

---

### **Applications of Binary Trees**

1. **Expression Evaluation**: Binary trees are used to represent expressions in infix, postfix, or prefix form. Expression trees represent mathematical expressions with operators as internal nodes and operands as leaf nodes.
   
2. **Binary Search Tree (BST)**: A binary tree where the left child is smaller and the right child is larger. BSTs support efficient search, insertion, and deletion operations.

3. **Decision Trees**: In machine learning and AI, binary trees are used to make decisions based on different conditions, leading to classification or regression tasks.

4. **Huffman Coding Tree**: Used for lossless data compression algorithms. It builds a binary tree where the most frequent data is encoded with shorter codes.

5. **Heap**: A complete binary tree used to implement priority queues.

---

### **Conclusion**

A **binary tree** is a fundamental data structure used for hierarchical data representation and efficient searching and sorting. Its various types, such as **binary search trees**, **balanced trees**, and **heaps**, provide

 optimal solutions to a wide range of problems. Traversal techniques such as **in-order**, **pre-order**, **post-order**, and **level-order** help in accessing nodes efficiently based on the specific needs of the problem.
