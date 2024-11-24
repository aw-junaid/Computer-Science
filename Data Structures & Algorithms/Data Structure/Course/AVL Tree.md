### **AVL Tree (Adelson-Velsky and Landis Tree)**

An **AVL Tree** is a **self-balancing binary search tree (BST)**, where the difference between the heights of the left and right subtrees (called the **balance factor**) of any node is at most 1. If at any time during an insertion or deletion operation the balance factor of any node becomes more than 1 or less than -1, the tree is restructured to restore balance through **rotations**.

---

### **Properties of AVL Tree**

1. **Binary Search Tree Property**: An AVL tree is a binary search tree, meaning for every node, the left subtree contains only nodes with smaller values, and the right subtree contains only nodes with larger values.
2. **Balance Factor**: For any node in the AVL tree, the **balance factor** is defined as:
   $\[
   \text{Balance Factor} = \text{Height of Left Subtree} - \text{Height of Right Subtree}
   \]$
   The balance factor of every node must be **-1, 0, or 1**. If the balance factor is outside this range, the tree needs to be rebalanced.
3. **Height of an AVL Tree**: The height of an AVL tree is always logarithmic in terms of the number of nodes, specifically **O(log n)** for balanced trees.

---

### **Balance Factor and Rotations**

The **balance factor** is the key metric used to maintain the balance of an AVL tree. If the balance factor of a node becomes greater than 1 or less than -1, we perform a **rotation** to restore the balance.

There are **four types of rotations** used in AVL trees to restore balance:

1. **Right Rotation (Single Rotation)**:
   - Performed when a node becomes **left-heavy** (i.e., balance factor > 1) due to an insertion in the left subtree of the left child.
   
```
      z                                      y
     / \                                   /   \
    y   T4      Right Rotation(z)      x       z
   / \      =>                         /  \    /  \
  x   T3                             T1     T2  T3   T4
 / \
T1   T2


```

2. **Left Rotation (Single Rotation)**:
   - Performed when a node becomes **right-heavy** (i.e., balance factor < -1) due to an insertion in the right subtree of the right child.
   
   ```
      z                                y
     /  \                            /   \
    T1   y        Left Rotation(z)  z      x
        / \     =>                  / \    / \
      T2   x                     T1   T2  T3   x
          / \ 
        T3   T4
   ```

3. **Left-Right Rotation (Double Rotation)**:
   - Performed when a node becomes **left-heavy** (balance factor > 1) but the left child is **right-heavy** (balance factor < 0).


```
      z                               z                           x
     /  \                            /  \                        /  \
    y    T4    Left Rotation(y)    x     T4  Right Rotation(z)  y     z
   / \      =>                      / \      =>                 /  \   /  \
 T1   x                          y      T3                  T1    T2 T3   T4
     /  \
   T2   T3
   
```

4. **Right-Left Rotation (Double Rotation)**:
   - Performed when a node becomes **right-heavy** (balance factor < -1) but the right child is **left-heavy** (balance factor > 0).

```

      z                            z                           x
     /  \                         /  \                        /  \
    T1    y     Right Rotation(y)  T1    x     Left Rotation(z)  y     z
          / \     =>              /  \      =>                 /  \   /  \
        x     T4                 T2    y                  T1   T2 T3   T4
       /  \                                          
     T2    T3
     
```


---

### **AVL Tree Operations**

1. **Insertion**:
   - Insert the new node as you would in a regular binary search tree (BST).
   - After insertion, check the balance factor of each ancestor node.
   - If any node has a balance factor of 2 or -2, perform the necessary rotation to restore balance.

2. **Deletion**:
   - Delete the node as you would in a regular binary search tree (BST).
   - After deletion, check the balance factor of each ancestor node.
   - If any node has a balance factor of 2 or -2, perform the necessary rotation to restore balance.

3. **Searching**:
   - Search operations in an AVL tree are similar to those in a regular BST.
   - Since the tree remains balanced, the time complexity for search is **O(log n)**.

---

### **Time Complexity in AVL Trees**

- **Insertion**: **O(log n)**, since the height of the AVL tree is always kept logarithmic.
- **Deletion**: **O(log n)**, for the same reason as insertion.
- **Search**: **O(log n)**, since the tree remains balanced.

---

### **Example of an AVL Tree**

Here’s an example of an AVL Tree after a series of insertions:

1. **Insert 30**:
   ```
      30
   ```
2. **Insert 20**:
   ```
      30
     /
    20
   ```
   Balance factor of 30 = 1, so no rotation needed.

3. **Insert 10**:
   ```
      30
     /
    20
   /
  10
   ```
   Balance factor of 30 = 2 (unbalanced), so a **Right Rotation** is performed:
   ```
      20
     /  \
    10   30
   ```

4. **Insert 25**:
   ```
      20
     /  \
    10   30
          /
         25
   ```
   Balance factor of 20 = 0, so no rotation needed.

---

### **AVL Tree Implementation (C++)**

Here is a simple implementation of the **AVL Tree**:

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

// Define the structure for the node
class Node {
public:
    int data;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        data = value;
        left = right = nullptr;
        height = 1;
    }
};

// AVL Tree Class
class AVLTree {
private:
    Node* root;

    // Function to get the height of the tree
    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    // Function to get the balance factor of the tree
    int balanceFactor(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    // Right Rotation
    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        // Perform rotation
        x->right = y;
        y->left = T2;

        // Update heights
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;  // Return new root
    }

    // Left Rotation
    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        // Perform rotation
        y->left = x;
        x->right = T2;

        // Update heights
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;  // Return new root
    }

    // Insertion operation
    Node* insert(Node* node, int value) {
        if (node == nullptr) return new Node(value);

        if (value < node->data) {
            node->left = insert(node->left, value);
        } else if (value > node->data) {
            node->right = insert(node->right, value);
        } else {
            return node;  // Duplicate values are not allowed
        }

        node->height = 1 + max(height(node->left), height(node->right));

        int balance = balanceFactor(node);

        // If node becomes unbalanced, then there are 4 cases

        // Left Left Case
        if (balance > 1 && value < node->left->data) {
            return rightRotate(node);
        }

        // Right Right Case
        if (balance < -1 && value > node->right->data) {
            return leftRotate(node);
        }

        // Left Right Case
        if (balance > 1 && value > node->left->data) {
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        // Right Left Case
        if (balance < -1 && value < node->right->data) {
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

public:
    AVLTree() {
        root = nullptr;
   

 }

    // Public insert method
    void insert(int value) {
        root = insert(root, value);
    }

    // In-order traversal
    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }

    // Helper function to print inorder traversal
    void printInOrder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(30);
    tree.insert(20);
    tree.insert(10);
    tree.insert(25);
    tree.insert(40);

    tree.printInOrder();  // Output: 10 20 25 30 40
    return 0;
}
```

---

### **Advantages of AVL Tree**

1. **Logarithmic Height**: The height of the AVL tree is guaranteed to be **O(log n)**, ensuring efficient operations.
2. **Efficient Operations**: All standard binary search tree operations (insert, delete, search) are guaranteed to be **O(log n)** due to the balanced nature of the tree.

---

### **Disadvantages of AVL Tree**

1. **Complexity of Rotations**: AVL trees require extra overhead for balancing after each insertion or deletion, which may result in additional complexity compared to simpler trees like standard binary search trees.
2. **Space Overhead**: Each node in the AVL tree needs to store an additional **height attribute**, increasing space usage compared to a simple binary search tree.

---

### **Applications of AVL Trees**

1. **Database Indexing**: AVL trees are used in databases to keep indexes balanced for fast searching.
2. **Memory Management**: AVL trees are used in managing memory efficiently, particularly in allocation and deallocation operations.
3. **Balanced Search**: AVL trees are used in applications where fast searching and maintaining balance are critical.

---

In conclusion, **AVL Trees** are self-balancing binary search trees that offer efficient searching, insertion, and deletion operations by maintaining a balanced height. The rotations and height updates ensure that the tree remains balanced, with logarithmic time complexity for key operations.
