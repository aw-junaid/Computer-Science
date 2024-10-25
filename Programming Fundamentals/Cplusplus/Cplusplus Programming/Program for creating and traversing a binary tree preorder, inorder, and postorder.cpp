#include <iostream>
using namespace std;

// node struct definition
struct Node {
    int data;
    Node* left;
    Node* right;
};

// function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// function to insert a node into the binary tree
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// function for preorder traversal
void preorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

// function for inorder traversal
void inorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

// function for postorder traversal
void postorderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 8);
    insertNode(root, 15);
    insertNode(root, 6);
    insertNode(root, 9);
    insertNode(root, 13);
    insertNode(root, 18);
    cout << "Preorder traversal: ";
    preorderTraversal(root);
    cout << endl;
    cout << "Inorder traversal: ";
    inorderTraversal(root);
    cout << endl;
    cout << "Postorder traversal: ";
    postorderTraversal(root);
    cout << endl;
    return 0;
}
