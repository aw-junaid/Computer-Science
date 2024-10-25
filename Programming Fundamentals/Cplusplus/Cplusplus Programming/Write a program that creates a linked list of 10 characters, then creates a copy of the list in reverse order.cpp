#include <iostream>

using namespace std;

struct Node {
    char data;
    Node* next;
};

Node* createNode(char data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node** head, char data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

Node* reverseList(Node* head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* next;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int main() {
    Node* head = NULL;
    Node* copy = NULL;

    // insert 10 characters in the list
    insertNode(&head, 'a');
    insertNode(&head, 'b');
    insertNode(&head, 'c');
    insertNode(&head, 'd');
    insertNode(&head, 'e');
    insertNode(&head, 'f');
    insertNode(&head, 'g');
    insertNode(&head, 'h');
    insertNode(&head, 'i');
    insertNode(&head, 'j');

    cout << "Original List: ";
    printList(head);

    // reverse the original list and create a copy
    copy = reverseList(head);

    cout << "Reversed List: ";
    printList(copy);

    return 0;
}
