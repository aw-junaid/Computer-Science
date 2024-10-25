#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Define a node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node with given data in ascending order
void insert(Node*& head, int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (head == nullptr) {
        // Empty list, insert at beginning
        head = newNode;
    } else if (data <= head->data) {
        // Insert at beginning
        newNode->next = head;
        head = newNode;
    } else {
        // Find the node to insert after
        Node* curr = head;
        while (curr->next != nullptr && curr->next->data < data) {
            curr = curr->next;
        }
        // Insert after the current node
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Function to print the linked list
void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    // Seed the random number generator
    srand(time(nullptr));

    Node* head = nullptr;

    // Insert 25 random integers in order
    for (int i = 0; i < 25; i++) {
        int data = rand() % 101; // Generate a random integer between 0 and 100
        insert(head, data);
    }

    // Print the linked list
    cout << "Linked List: ";
    printList(head);

    return 0;
}
