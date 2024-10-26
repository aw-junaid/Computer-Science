**Heap Sort Algorithm: An Overview**

Heap Sort is a comparison-based sorting algorithm that uses a binary heap data structure to efficiently sort an array or list. It divides the input into a sorted and an unsorted region, and the binary heap ensures that the largest element in the unsorted region is always at the root of the heap. By repeatedly extracting the maximum element from the heap and swapping it with the last element of the unsorted region, the array is sorted in ascending order. Heap Sort is an in-place sorting algorithm with a time complexity of O(n log n).

**Working of Heap Sort Algorithm**

1. **Build Heap**: First, the algorithm builds a binary heap from the input array. This is done by converting the input array into a max heap (for ascending order sorting) or a min heap (for descending order sorting).

2. **Heapify**: The algorithm swaps the root (the largest element in the unsorted region) with the last element of the unsorted region. This ensures that the largest element is now at its correct position in the sorted part of the array.

3. **Heapify Down**: After swapping the root, the heap property may be violated. To restore the heap property, the algorithm performs a heapify operation on the root, pushing it down to its correct position.

4. **Repeat**: Steps 2 and 3 are repeated until the entire array is sorted.

**Example Use Cases for Heap Sort Algorithm**

1. **Sorting Large Datasets**: Heap Sort is efficient for sorting large datasets due to its O(n log n) time complexity.

2. **Priority Queue**: Heap data structure is widely used to implement priority queues, and Heap Sort can be used to efficiently sort priority queue elements.

3. **Selection of Top k Elements**: Heap Sort can be used to select the top k elements from a large dataset.

**Implementation of Heap Sort in Python, C++, Rust, and Ruby**

**Python Code for Heap Sort:**

```python
def heapify(arr, n, i):
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n and arr[left] > arr[largest]:
        largest = left

    if right < n and arr[right] > arr[largest]:
        largest = right

    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)

    # Build max heap
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)

    # Extract elements one by one
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)

# Example usage:
my_list = [12, 11, 13, 5, 6, 7]
heap_sort(my_list)
print(my_list)
```

**C++ Code for Heap Sort:**

```cpp
#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

void heap_sort(int arr[], int n) {
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}

int main() {
    int myArray[] = {12, 11, 13, 5, 6, 7};
    int size = sizeof(myArray) / sizeof(myArray[0]);
    heap_sort(myArray, size);

    for (int i = 0; i < size; i++) {
        cout << myArray[i] << " ";
    }

    return 0;
}
```

**Rust Code for Heap Sort:**

```rust
fn heapify(arr: &mut [i32], n: usize, i: usize) {
    let mut largest = i;
    let left = 2 * i + 1;
    let right = 2 * i + 2;

    if left < n && arr[left] > arr[largest] {
        largest = left;
    }

    if right < n && arr[right] > arr[largest] {
        largest = right;
    }

    if largest != i {
        arr.swap(i, largest);
        heapify(arr, n, largest);
    }
}

fn heap_sort(arr: &mut [i32]) {
    let n = arr.len();

    // Build max heap
    for i in (0..n / 2).rev() {
        heapify(arr, n, i);
    }

    // Extract elements one by one
    for i in (1..n).rev() {
        arr.swap(0, i);
        heapify(arr, i, 0);
    }
}

fn main() {
    let mut my_array = [12, 11, 13, 5, 6, 7];
    heap_sort(&mut my_array);

    for num in my_array.iter() {
        print!("{} ", num);
    }
}
```

**Ruby Code for Heap Sort:**

```ruby
def heapify(arr, n, i)
    largest = i
    left = 2 * i + 1
    right = 2 * i + 2

    if left < n && arr[left] > arr[largest]
        largest = left
    end

    if right < n && arr[right] > arr[largest]
        largest = right
    end

    if largest != i
        arr[i], arr[largest] = arr[largest], arr[i]
        heapify(arr, n, largest)
    end
end

def heap_sort(arr)
    n = arr.length

    # Build max heap
    (n / 2 - 1).downto(0).each do |i|
        heapify(arr, n, i)
    end

    # Extract elements one by one
    (n - 1).downto(1).each do |i|
        arr[0], arr[i] = arr[i], arr[0]
        heapify(arr, i, 0)
    end
end

# Example usage:
my_array = [12, 11, 13, 5, 6, 7]
heap_sort(my_array)
puts my_array.join(" ")
```

**Conclusion**

Heap Sort is an efficient in-place sorting algorithm based on the binary heap data structure. By converting

 the input array into a max heap and repeatedly extracting the maximum element from the heap, Heap Sort efficiently sorts the array in ascending order. It is particularly useful for sorting large datasets and implementing priority queues. The provided code examples in Python, C++, Rust, and Ruby demonstrate the implementation of Heap Sort, enabling you to apply this sorting algorithm in your projects for various sorting and priority queue applications.
