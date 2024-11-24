### **B+ Tree**

A **B+ Tree** is an extension of the **B-tree** data structure. It is a self-balancing tree structure used extensively in databases and file systems for efficient data storage, retrieval, and indexing. Unlike the B-tree, where data can be stored both in internal and leaf nodes, the B+ tree stores data only at the **leaf nodes**, while the internal nodes store only keys to guide the search process.

---

### **Properties of B+ Tree**

1. **Balanced**: Like the B-tree, the B+ tree is balanced, meaning the height from the root to any leaf node is the same. This ensures logarithmic search, insertion, and deletion times.
2. **Nodes**:
   - **Internal Nodes**: The internal nodes only store keys, which are used to guide the search for data. They do not store actual data.
   - **Leaf Nodes**: The actual data records (or pointers to data records) are stored in the leaf nodes. These nodes are **linked** in a doubly linked list, allowing for efficient range queries and sequential access.
3. **Ordered Structure**: Keys in both internal and leaf nodes are stored in **ascending order**.
4. **Linked Leaf Nodes**: All leaf nodes in a B+ tree are linked together using a **doubly linked list**. This allows for easy traversal of the tree in **sorted order**, which is especially useful for **range queries**.
5. **Height**: Like the B-tree, the height of a B+ tree is logarithmic, so search, insertion, and deletion operations have a time complexity of **O(log n)**.

---

### **B+ Tree Operations**

1. **Search**:
   - The search operation in a B+ tree is very similar to that in a B-tree. The search begins at the root node and moves down to the appropriate child node based on comparisons.
   - The key difference is that in a B+ tree, the search continues until the leaf node is reached, where the actual data can be found.
   - **Time Complexity**: **O(log n)**.

2. **Insertion**:
   - Insertion in a B+ tree follows a process similar to the B-tree, where the correct leaf node is found by traversing the tree.
   - If the leaf node has space, the new key is inserted. If the leaf node is full, it is **split**, and the middle key is promoted to the parent node.
   - If a node becomes too full, it may propagate the split upwards, and if the root is split, the tree height increases by 1.
   - **Time Complexity**: **O(log n)**.

3. **Deletion**:
   - Deletion in a B+ tree involves finding the key in the leaf node and removing it.
   - If the removal causes a node to have fewer than the minimum required number of keys, **underflow** occurs. The tree may borrow a key from a neighboring sibling or merge nodes to maintain balance.
   - **Time Complexity**: **O(log n)**.

4. **Range Query**:
   - A key advantage of the B+ tree is the linked leaf nodes, which allow efficient **range queries**. Once the starting key is located in the leaf node, it is easy to traverse through the linked list of leaf nodes to retrieve all keys within a given range.
   - **Time Complexity**: For a range query, the search for the starting point is **O(log n)**, and traversing the linked leaf nodes takes **O(k)**, where **k** is the number of keys in the range.

---

### **B+ Tree Example**

Consider a **B+ Tree** of **order 4** (maximum of 3 keys per node and 4 children per internal node).

1. Insert 10:

```

   [10]

2. Insert 20:

   [10, 20]

3. Insert 5:

   [5, 10, 20]

4. Insert 30 (leaf node is full, split occurs):

   Internal Node: [10]
   /     \
   [5]   [20, 30]

5. Insert 25 (leaf node is full, split occurs):

   Internal Node: [10, 20]
   /    |    \
  [5]  [15] [25, 30]

```


In this case, the **internal nodes** only store keys to guide the search, while the **leaf nodes** store actual data. Additionally, the leaf nodes are linked together for efficient sequential access.



### **Key Differences Between B-Tree and B+ Tree**

1. **Data Storage**:
   - **B-Tree**: Data is stored in both internal and leaf nodes.
   - **B+ Tree**: Data is only stored in the leaf nodes; internal nodes store only keys for navigation.
   
2. **Leaf Node Linking**:
   - **B-Tree**: No linking between leaf nodes.
   - **B+ Tree**: Leaf nodes are linked together in a **doubly linked list**, which allows efficient range queries and ordered traversal.

3. **Efficiency**:
   - **B-Tree**: Can be more efficient for certain search operations where data might be needed at any internal node.
   - **B+ Tree**: More efficient for **range queries** and **sequential access** due to the linked leaf nodes.

4. **Height**:
   - Both B-trees and B+ trees have logarithmic height, ensuring efficient search, insertion, and deletion operations. The height is proportional to **log m(n)**, where **m** is the order of the tree, and **n** is the number of elements.

---

### **Advantages of B+ Tree**

1. **Efficient Range Queries**: Due to the linked leaf nodes, B+ trees provide efficient sequential access and are particularly well-suited for range queries.
2. **Balanced Structure**: B+ trees remain balanced, ensuring that the height of the tree is logarithmic, and all operations (search, insert, delete) have **O(log n)** time complexity.
3. **Efficient Use of Disk**: B+ trees minimize disk access by storing multiple keys in each node, which is especially useful in systems where disk I/O is expensive.
4. **Ordered Data**: Since the leaf nodes are linked in order, it is easy to perform in-order traversal or find records in a given range.

---

### **Disadvantages of B+ Tree**

1. **Complexity**: B+ trees are more complex to implement compared to simpler trees like binary search trees or even B-trees.
2. **Memory Overhead**: Like B-trees, B+ trees have extra overhead due to the need to store additional pointers and maintain linked leaf nodes.

---

### **Applications of B+ Tree**

1. **Database Indexing**: B+ trees are widely used in database systems for indexing, as they allow for fast search, insertion, deletion, and range queries.
2. **File Systems**: B+ trees are used in file systems to manage file directories and provide fast access to file data blocks.
3. **Data Warehousing**: B+ trees are used to index large volumes of data, enabling fast queries and efficient storage management.
4. **Multilevel Indexing**: In systems requiring multilevel indexing for large datasets, B+ trees provide an efficient and scalable solution.

---

### **B+ Tree Time Complexity**

- **Search**: **O(log n)**, since the tree is balanced and we only need to traverse from root to leaf nodes.
- **Insertion**: **O(log n)**, with occasional node splitting.
- **Deletion**: **O(log n)**, with occasional node merging or redistribution.
- **Range Queries**: **O(log n + k)**, where **k** is the number of results in the range.

---

### **B+ Tree Example in C++**

Here is a simple implementation of a **B+ Tree** (only a basic structure for illustration):


```cpp

#include <iostream>
using namespace std;

class Node {
public:
    int *keys;
    Node **children;
    int numKeys;
    bool isLeaf;

    Node(int order, bool leaf);
    void insertNonFull(int key, int order);
    void splitChild(int i, Node *y, int order);
};

class BPlusTree {
public:
    Node *root;
    int order;

    BPlusTree(int order);
    void insert(int key);
    void search(int key);
    void printInOrder(Node *node);
};

Node::Node(int order, bool leaf) {
    this->isLeaf = leaf;
    this->numKeys = 0;
    this->keys = new int[order - 1];
    this->children = new Node *[order];
}

void Node::insertNonFull(int key, int order) {
    int i = numKeys - 1;
    if (isLeaf) {
        while (i >= 0 && keys[i] > key) {
            keys[i + 1] = keys[i];
            i--;
        }
        keys[i + 1] = key;
        numKeys++;
    } else {
        while (i >= 0 && keys[i] > key) {
            i--;
        }
        i++;
        if (children[i]->numKeys == order - 1) {
            splitChild(i, children[i], order);
            if (keys[i] < key) {
                i++;
            }
        }
        children[i]->insertNonFull(key, order);
    }
}

void Node::splitChild(int i, Node *y, int order

) {
    Node *z = new Node(order, y->isLeaf);
    z->numKeys = order / 2;
    for (int j = 0; j < order / 2; j++) {
        z->keys[j] = y->keys[j + order / 2];
    }
    if (!y->isLeaf) {
        for (int j = 0; j < order / 2 + 1; j++) {
            z->children[j] = y->children[j + order / 2];
        }
    }
    y->numKeys = order / 2;
    for (int j = numKeys; j >= i + 1; j--) {
        children[j + 1] = children[j];
    }
    children[i + 1] = z;
    for (int j = numKeys - 1; j >= i; j--) {
        keys[j + 1] = keys[j];
    }
    keys[i] = y->keys[order / 2];
    numKeys++;
}

BPlusTree::BPlusTree(int order) {
    this->order = order;
    root = new Node(order, true);
}

void BPlusTree::insert(int key) {
    if (root->numKeys == order - 1) {
        Node *newRoot = new Node(order, false);
        newRoot->children[0] = root;
        newRoot->splitChild(0, root, order);
        root = newRoot;
    }
    root->insertNonFull(key, order);
}

void BPlusTree::printInOrder(Node *node) {
    if (node != nullptr) {
        for (int i = 0; i < node->numKeys; i++) {
            printInOrder(node->children[i]);
            cout << node->keys[i] << " ";
        }
        printInOrder(node->children[node->numKeys]);
    }
}

int main() {
    BPlusTree tree(4); // Order 4 B+ tree

    tree.insert(10);
    tree.insert(20);
    tree.insert(5);
    tree.insert(30);
    tree.insert(25);

    tree.printInOrder(tree.root);  // Output: 5 10 20 25 30

    return 0;
}
```

---

### **Conclusion**

The **B+ Tree** is an advanced data structure derived from the **B-tree**, offering enhancements for **range queries** and **sequential access** due to the linked leaf nodes. It maintains the balanced, efficient structure of the B-tree, with the added benefit of optimizing disk I/O for large datasets, making it ideal for use in database indexing, file systems, and data warehousing.
