**Counting Sort Algorithm: An Overview**

Counting Sort is a non-comparison-based sorting algorithm that efficiently sorts an array or list with integer elements within a specific range. It works by counting the occurrences of each unique element in the input array and then using this count information to determine the correct position of each element in the sorted output. Counting Sort has a time complexity of O(n+k), where n is the number of elements in the input array and k is the range of input values. It is particularly useful for sorting datasets with a limited range of integers.

**Working of Counting Sort Algorithm**

1. **Counting Frequencies**: The algorithm starts by counting the occurrences of each unique element in the input array and stores this information in an auxiliary count array.

2. **Calculate Prefix Sum**: The algorithm calculates the prefix sum of the count array. The prefix sum indicates the position of each unique element in the sorted output.

3. **Build Sorted Array**: The algorithm builds the sorted output array by placing each element in its correct position according to the prefix sum and decrements its count in the count array.

**Example Use Cases for Counting Sort Algorithm**

1. **Sorting Positive Integers**: Counting Sort is efficient for sorting positive integers within a limited range.

2. **Character Sorting**: Counting Sort can be used to sort characters or strings based on their ASCII values.

3. **Sorting with Limited Range**: When the range of input values is known and small, Counting Sort can outperform other comparison-based sorting algorithms.

**Implementation of Counting Sort in Python, C++, Rust, and Ruby**

**Python Code for Counting Sort:**

```python
def counting_sort(arr):
    # Find the maximum element in the array
    max_val = max(arr)

    # Create a count array to store the frequencies of each element
    count = [0] * (max_val + 1)

    # Count the occurrences of each element in the input array
    for num in arr:
        count[num] += 1

    # Calculate the prefix sum of the count array
    for i in range(1, len(count)):
        count[i] += count[i - 1]

    # Build the sorted output array using the prefix sum
    sorted_arr = [0] * len(arr)
    for num in arr:
        sorted_arr[count[num] - 1] = num
        count[num] -= 1

    return sorted_arr

# Example usage:
my_list = [4, 2, 2, 8, 3, 3, 1]
sorted_list = counting_sort(my_list)
print(sorted_list)
```

**C++ Code for Counting Sort:**

```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> counting_sort(vector<int>& arr) {
    // Find the maximum element in the array
    int max_val = *max_element(arr.begin(), arr.end());

    // Create a count array to store the frequencies of each element
    vector<int> count(max_val + 1, 0);

    // Count the occurrences of each element in the input array
    for (int num : arr) {
        count[num]++;
    }

    // Calculate the prefix sum of the count array
    for (int i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // Build the sorted output array using the prefix sum
    vector<int> sorted_arr(arr.size());
    for (int num : arr) {
        sorted_arr[count[num] - 1] = num;
        count[num]--;
    }

    return sorted_arr;
}

int main() {
    vector<int> myArray = {4, 2, 2, 8, 3, 3, 1};
    vector<int> sortedArray = counting_sort(myArray);

    for (int num : sortedArray) {
        cout << num << " ";
    }

    return 0;
}
```

**Rust Code for Counting Sort:**

```rust
fn counting_sort(arr: &mut [usize]) -> Vec<usize> {
    // Find the maximum element in the array
    let max_val = *arr.iter().max().unwrap();

    // Create a count array to store the frequencies of each element
    let mut count = vec![0; max_val + 1];

    // Count the occurrences of each element in the input array
    for &num in arr.iter() {
        count[num] += 1;
    }

    // Calculate the prefix sum of the count array
    for i in 1..count.len() {
        count[i] += count[i - 1];
    }

    // Build the sorted output array using the prefix sum
    let mut sorted_arr = vec![0; arr.len()];
    for &num in arr.iter().rev() {
        sorted_arr[count[num] - 1] = num;
        count[num] -= 1;
    }

    sorted_arr
}

fn main() {
    let mut my_array = vec![4, 2, 2, 8, 3, 3, 1];
    let sorted_array = counting_sort(&mut my_array);

    for num in sorted_array {
        print!("{} ", num);
    }
}
```

**Ruby Code for Counting Sort:**

```ruby
def counting_sort(arr)
    # Find the maximum element in the array
    max_val = arr.max

    # Create a count array to store the frequencies of each element
    count = Array.new(max_val + 1, 0)

    # Count the occurrences of each element in the input array
    arr.each { |num| count[num] += 1 }

    # Calculate the prefix sum of the count array
    (1..max_val).each { |i| count[i] += count[i - 1] }

    # Build the sorted output array using the prefix sum
    sorted_arr = Array.new(arr.length)
    arr.reverse_each { |num| sorted_arr[count[num] - 1] = num; count[num] -= 1 }

    sorted_arr
end

# Example usage:
my_array = [4, 2, 2, 8, 3, 3, 1]
sorted_array = counting_sort(my_array)
puts sorted_array.join(" ")
```

**Conclusion**

Counting Sort is an efficient sorting algorithm for arrays or lists with integer elements within a specific range. By counting the occurrences of each unique element and using this count information to determine the correct position of each element in the sorted output, Counting Sort efficiently sorts data with a time complexity of O(n+k). It is particularly useful for sorting positive integers and characters or strings based on their ASCII values. The provided code examples in Python, C++, Rust, and Ruby demonstrate the implementation of Counting Sort, enabling you to utilize this sorting algorithm for efficient sorting of datasets with limited ranges of integer elements.
