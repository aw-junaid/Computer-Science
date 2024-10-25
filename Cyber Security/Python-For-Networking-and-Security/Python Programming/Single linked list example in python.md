A singly linked list is a linear data structure where each element (node) points to the next element in the list. Here's a simple example of a singly linked list implementation in Python:

```python
class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None

    def append(self, data):
        new_node = Node(data)
        if not self.head:
            self.head = new_node
            return
        current = self.head
        while current.next:
            current = current.next
        current.next = new_node

    def display(self):
        current = self.head
        while current:
            print(current.data, end=" -> ")
            current = current.next
        print("None")

# Create a linked list
linked_list = LinkedList()
linked_list.append(10)
linked_list.append(20)
linked_list.append(30)

# Display the linked list
linked_list.display()
```

In this example, we have a `Node` class representing individual elements of the linked list, and a `LinkedList` class that manages the linked list operations. The `append()` method adds elements to the end of the linked list, and the `display()` method prints the elements.

When you run this code, the output will be:

```
10 -> 20 -> 30 -> None
```

This is a basic implementation of a singly linked list. Keep in mind that real-world linked list implementations might involve additional features and methods for more advanced use cases.
