#include <iostream>
using namespace std;

const int MAX = 10; // Maximum size of the stack

class Stack {
private:
    int top;        // Index of the top element in the stack
    int arr[MAX];   // Array to hold the elements of the stack

public:
    Stack() { top = -1; }   // Constructor to initialize the stack

    bool push(int x) {
        // Check if stack is full
        if (top == MAX - 1) {
            cout << "Stack Overflow!" << endl;
            return false;
        }
        // Increment top and insert element
        arr[++top] = x;
        return true;
    }

    bool pop() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack Underflow!" << endl;
            return false;
        }
        // Decrement top to remove element
        top--;
        return true;
    }

    int peek() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return -1;
        }
        // Return the top element
        return arr[top];
    }

    bool isEmpty() {
        // Check if stack is empty
        return (top == -1);
    }

    bool isFull() {
        // Check if stack is full
        return (top == MAX - 1);
    }

    void display() {
        // Check if stack is empty
        if (top == -1) {
            cout << "Stack is Empty!" << endl;
            return;
        }
        // Display the elements of the stack
        cout << "Stack: ";
        for (int i = 0; i <= top; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};

int main() {
    Stack s;     // Create an instance of the stack

    s.push(5);   // Insert elements into the stack
    s.push(10);
    s.push(15);
    s.push(20);

    s.display(); // Display the elements of the stack

    s.pop();     // Remove an element from the stack
    s.pop();

    s.display(); // Display the elements of the stack

    cout << "Top element: " << s.peek() << endl; // Display the top element

    return 0;
}
