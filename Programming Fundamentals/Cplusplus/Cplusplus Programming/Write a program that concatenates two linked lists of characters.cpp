#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    char data;
    Node* next;
};

// Function to add a new node at the end of the linked list
void addNode(Node*& head, char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

// Function to concatenate two linked lists
Node* concatenateLists(Node* head1, Node* head2) {
    Node* result = NULL;
    Node* temp = head1;
    while (temp != NULL) {
        addNode(result, temp->data);
        temp = temp->next;
    }
    temp = head2;
    while (temp != NULL) {
        addNode(result, temp->data);
        temp = temp->next;
    }
    return result;
}

// Function to display the linked list
void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Create the first linked list
    Node* head1 = NULL;
    addNode(head1, 'H');
    addNode(head1, 'e');
    addNode(head1, 'l');
    addNode(head1, 'l');
    addNode(head1, 'o');
    cout << "List 1: ";
    displayList(head1);

    // Create the second linked list
    Node* head2 = NULL;
    addNode(head2, 'W');
    addNode(head2, 'o');
    addNode(head2, 'r');
    addNode(head2, 'l');
    addNode(head2, 'd');
    cout << "List 2: ";
    displayList(head2);

    // Concatenate the two linked lists
    Node* result = concatenateLists(head1, head2);
    cout << "Concatenated list: ";
    displayList(result);

    return 0;
}
