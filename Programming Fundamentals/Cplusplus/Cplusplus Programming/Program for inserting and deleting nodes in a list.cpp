#include <iostream>
using namespace std;

// Define the Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the list
void insert(Node** head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Function to delete a node from the list
void deleteNode(Node** head, int key) {
    Node* temp = *head;
    Node* prev = NULL;

    // If head node itself holds the key to be deleted
    if (temp != NULL && temp->data == key) {
        *head = temp->next; // Change head
        delete temp; // Free memory
        return;
    }

    // Search for the key to be deleted, keep track of the previous node
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    // If key was not present in linked list
    if (temp == NULL) return;

    // Unlink the node from linked list
    prev->next = temp->next;
    delete temp; // Free memory
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;

    // Insert some nodes
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);

    cout << "Original List: ";
    printList(head);

    // Delete some nodes
    deleteNode(&head, 20);
    cout << "List after deleting 20: ";
    printList(head);

    deleteNode(&head, 30);
    cout << "List after deleting 30: ";
    printList(head);

    deleteNode(&head, 50);
    cout << "List after deleting 50: ";
    printList(head);

    return 0;
}
