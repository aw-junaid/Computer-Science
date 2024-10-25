#include <iostream>

using namespace std;

// Define structure for stack node
struct StackNode {
    int data;
    StackNode* next;
};

// Define class for dynamic stack
class DynamicStack {
private:
    StackNode* top;
public:
    // Constructor
    DynamicStack() {
        top = NULL;
    }
    // Destructor
    ~DynamicStack() {
        while (top != NULL) {
            StackNode* temp = top;
            top = top->next;
            delete temp;
        }
    }
    // Function to push a new element on top of stack
    void push(int data) {
        StackNode* new_node = new StackNode;
        new_node->data = data;
        new_node->next = top;
        top = new_node;
        cout << "Pushed " << data << " onto the stack." << endl;
    }
};

int main() {
    // Create dynamic stack object
    DynamicStack my_stack;

    // Push some elements onto the stack
    my_stack.push(10);
    my_stack.push(20);
    my_stack.push(30);

    return 0;
}
