#include <iostream>
#include <vector>

using namespace std;

// Function to merge two ordered lists of integers
vector<int> mergeLists(const vector<int>& list1, const vector<int>& list2) {
    // Create a vector to store the merged list
    vector<int> mergedList;

    // Declare iterators for both input lists
    auto it1 = list1.begin();
    auto it2 = list2.begin();

    // Merge the two lists while they still have elements
    while (it1 != list1.end() && it2 != list2.end()) {
        if (*it1 < *it2) {
            mergedList.push_back(*it1);
            ++it1;
        } else {
            mergedList.push_back(*it2);
            ++it2;
        }
    }

    // Copy any remaining elements from list1 to the merged list
    while (it1 != list1.end()) {
        mergedList.push_back(*it1);
        ++it1;
    }

    // Copy any remaining elements from list2 to the merged list
    while (it2 != list2.end()) {
        mergedList.push_back(*it2);
        ++it2;
    }

    // Return the merged list
    return mergedList;
}

int main() {
    // Create two ordered lists of integers
    vector<int> list1 = {1, 3, 5, 7, 9};
    vector<int> list2 = {2, 4, 6, 8, 10};

    // Merge the two lists and store the result in a new list
    vector<int> mergedList = mergeLists(list1, list2);

    // Print the merged list
    for (int num : mergedList) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
