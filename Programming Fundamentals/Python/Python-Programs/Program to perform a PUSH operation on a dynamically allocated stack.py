class Stack:
    def __init__(self):
        self.items = []

    def push(self, item):
        self.items.append(item)
        print(f"{item} pushed to stack")

    def display(self):
        print("Stack elements are:")
        for item in self.items:
            print(item)

# Creating an empty stack
stack = Stack()

# Pushing elements to the stack
stack.push(10)
stack.push(20)
stack.push(30)

# Displaying the elements of the stack
stack.display()
