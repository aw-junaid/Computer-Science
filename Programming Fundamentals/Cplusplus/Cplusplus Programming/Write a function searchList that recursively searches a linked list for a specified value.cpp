#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertNode(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

bool searchList(Node* head, int value) {
    if (head == nullptr) {
        return false;
    }
    if (head->data == value) {
        return true;
    }
    return searchList(head->next, value);
}

int main() {
    Node* head = nullptr;
    insertNode(head, 5);
    insertNode(head, 10);
    insertNode(head, 15);
    insertNode(head, 20);

    int value = 10;
    bool found = searchList(head, value);
    if (found) {
        cout << "Value " << value << " found in the list." << endl;
    } else {
        cout << "Value " << value << " not found in the list." << endl;
    }

    return 0;
}
