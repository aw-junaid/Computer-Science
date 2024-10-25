#include <iostream>
using namespace std;

// Define a structure for the node
struct Node {
    int data;
    Node* next;
};

// Define a class for the queue
class Queue {
private:
    Node* front;
    Node* rear;
public:
    // Constructor
    Queue() {
        front = NULL;
        rear = NULL;
    }

    // Function to check if the queue is empty
    bool isEmpty() {
        return (front == NULL);
    }

    // Function to enqueue an element to the queue
    void enqueue(int x) {
        Node* temp = new Node;
        temp->data = x;
        temp->next = NULL;
        if (front == NULL && rear == NULL) {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }

    // Function to dequeue an element from the queue
    void dequeue() {
        Node* temp = front;
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return;
        }
        if (front == rear) {
            front = rear = NULL;
        }
        else {
            front = front->next;
        }
        delete temp;
    }

    // Function to display the queue
    void display() {
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    // Function to get the front element of the queue
    int frontElement() {
        if (front == NULL) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
};

int main() {
    // Create an object of the Queue class
    Queue q;
    // Enqueue elements to the queue
    q.enqueue(5);
    q.enqueue(10);
    q.enqueue(15);
    q.enqueue(20);
    // Display the queue
    cout << "Queue elements: ";
    q.display();
    // Dequeue an element from the queue
    q.dequeue();
    // Display the queue after dequeuing an element
    cout << "Queue elements: ";
    q.display();
    // Get the front element of the queue
    cout << "Front element of the queue: " << q.frontElement() << endl;
    // Check if the queue is empty
    if (q.isEmpty()) {
        cout << "Queue is empty" << endl;
    }
    else {
        cout << "Queue is not empty" << endl;
    }
    return 0;
}
