**Floyd's Cycle Detection Algorithm: An Overview**

Floyd's Cycle Detection Algorithm, also known as the "Tortoise and the Hare" algorithm, is a cycle detection algorithm used to detect cycles in a linked list or any sequence of elements. This algorithm is based on the idea of two pointers moving through the sequence at different speeds. If there is a cycle in the sequence, the two pointers will eventually meet at some point, indicating the presence of a cycle.

Floyd's Cycle Detection Algorithm is particularly useful for detecting cycles in linked lists, identifying duplicate elements in an array, and finding repeated patterns in sequences.

**Working of Floyd's Cycle Detection Algorithm**

1. **Step 1: Initialization**: The algorithm starts with two pointers, commonly referred to as "slow" and "fast," initialized to the head of the sequence.

2. **Step 2: Movement**: In each iteration, the slow pointer moves one step forward, while the fast pointer moves two steps forward in the sequence.

3. **Step 3: Cycle Detection**: If there is no cycle in the sequence, the fast pointer will eventually reach the end of the sequence, and the algorithm terminates, indicating no cycle. However, if there is a cycle, the fast pointer will eventually catch up to the slow pointer.

4. **Step 4: Cycle Detection (Continued)**: Once the fast pointer catches up to the slow pointer, it means that the two pointers have entered the cycle. At this point, we reset the slow pointer to the head of the sequence.

5. **Step 5: Cycle Length Determination**: The slow pointer starts moving one step at a time, and the fast pointer continues moving two steps at a time. When the two pointers meet again, the number of steps taken by the slow pointer to reach this point gives us the length of the cycle.

6. **Step 6: Cycle Start Point Identification**: After determining the cycle length, we reset the fast pointer to the head of the sequence while keeping the slow pointer at the meeting point. Both pointers then move one step at a time until they meet again. The meeting point will be the start of the cycle.

7. **Step 7: Cycle Removal or Identification**: Depending on the application, we can either remove the cycle from the sequence or simply identify the cycle and its starting point.

**Example Use Cases for Floyd's Cycle Detection Algorithm**

1. **Linked List Cycle Detection**: Floyd's Algorithm is used to detect cycles in a linked list, helping to identify circular dependencies or infinite loops.

2. **Duplicate Element Detection**: The algorithm can identify duplicate elements in an array by treating the array as a sequence.

3. **Repeating Patterns**: In sequences, such as DNA sequences or sensor readings, the algorithm can detect repeated patterns or cycles.

**Implementation of Floyd's Cycle Detection Algorithm in Python, C++, Rust, and Ruby**

**Python Code for Floyd's Cycle Detection Algorithm:**

```python
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

def detect_cycle(head):
    slow = head
    fast = head

    while fast and fast.next:
        slow = slow.next
        fast = fast.next.next

        if slow == fast:
            break

    if not fast or not fast.next:
        return None

    slow = head
    while slow != fast:
        slow = slow.next
        fast = fast.next

    return slow

# Example usage:
# Create a linked list with a cycle
node1 = ListNode(1)
node2 = ListNode(2)
node3 = ListNode(3)
node4 = ListNode(4)
node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2

start_of_cycle = detect_cycle(node1)
print(start_of_cycle.val)  # Output: 2
```

**C++ Code for Floyd's Cycle Detection Algorithm:**

```cpp
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int val) : val(val), next(nullptr) {}
};

ListNode* detect_cycle(ListNode* head) {
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break;
        }
    }

    if (!fast || !fast->next) {
        return nullptr;
    }

    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}

int main() {
    // Create a linked list with a cycle
    ListNode* node1 = new ListNode(1);
    ListNode* node2 = new ListNode(2);
    ListNode* node3 = new ListNode(3);
    ListNode* node4 = new ListNode(4);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node2;

    ListNode* start_of_cycle = detect_cycle(node1);
    std::cout << start_of_cycle->val << std::endl;  // Output: 2

    // Don't forget to deallocate memory
    delete node1;
    delete node2;
    delete node3;
    delete node4;

    return 0;
}
```

**Rust Code for Floyd's Cycle Detection Algorithm:**

```rust
use std::collections::HashSet;

#[derive(Debug, PartialEq, Eq)]
struct ListNode {
    val: i32,
    next: Option<Box<ListNode>>,
}

impl ListNode {
    fn new(val: i32) -> Self {
        ListNode { val, next: None }
    }

    fn append(&mut self, val: i32) {
        let mut current = self;
        while let Some(ref mut node) = current.next {
            current = node;
        }
        current.next = Some(Box::new(ListNode::new(val)));
    }
}

fn detect_cycle(head: Option<Box<ListNode>>) -> Option<i32> {
    let mut slow = &head;
    let mut fast = &head;

    while fast.is_some() && fast.as_ref()?.next.is_some() {
        slow = &slow.as_ref()?.next;
        fast = &fast.as_ref()?.next.as_ref()?.next;

        if slow == fast {
            break;
        }
    }

    if fast.is_none() || fast.as_ref()?.next.is_none() {
        return None;
    }

    slow = &head;
    while slow != fast {
        slow = &slow.as_ref()?.next;
        fast = &fast.as_ref()?.next;
    }

    slow.map(|node| node.val)
}

fn main() {
    // Create a linked list with a cycle
    let mut node1 = ListNode::new(1);
    let mut node2 = ListNode::new(2);
    let mut node3 = ListNode::new(3);
    let mut node4 = ListNode::new(4);
    node1.next = Some(Box::new(node2));
    node2.next = Some(Box::new(node3));
    node3.next = Some(Box::new(node4));
    node4.next = Some(Box::new(node2));

    let start_of_cycle = detect_cycle(Some(Box::new(node

1)));
    println!("{:?}", start_of_cycle);  // Output: Some(2)
}
```

**Ruby Code for Floyd's Cycle Detection Algorithm:**

```ruby
class ListNode
  attr_accessor :val, :next
  def initialize(val)
    @val = val
    @next = nil
  end
end

def detect_cycle(head)
  slow = head
  fast = head

  while fast && fast.next
    slow = slow.next
    fast = fast.next.next

    break if slow == fast
  end

  return nil unless fast && fast.next

  slow = head
  while slow != fast
    slow = slow.next
    fast = fast.next
  end

  slow.val
end

# Example usage:
# Create a linked list with a cycle
node1 = ListNode.new(1)
node2 = ListNode.new(2)
node3 = ListNode.new(3)
node4 = ListNode.new(4)
node1.next = node2
node2.next = node3
node3.next = node4
node4.next = node2

start_of_cycle = detect_cycle(node1)
puts start_of_cycle  # Output: 2
```

**Conclusion**

Floyd's Cycle Detection Algorithm, also known as the "Tortoise and the Hare" algorithm, is a powerful tool for detecting cycles in linked lists and sequences of elements. Its applications in detecting cycles in linked lists, identifying duplicate elements, and finding repeated patterns make it valuable in various scenarios. The provided code examples in Python, C++, Rust, and Ruby demonstrate the implementation of Floyd's Cycle Detection Algorithm, enabling you to detect cycles efficiently in your projects and applications.
