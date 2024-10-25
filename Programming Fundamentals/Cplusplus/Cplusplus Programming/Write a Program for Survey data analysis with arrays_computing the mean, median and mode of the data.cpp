#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_SIZE = 100;

// Function to compute the mean of the survey data
double computeMean(int data[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return static_cast<double>(sum) / size;
}

// Function to compute the median of the survey data
double computeMedian(int data[], int size) {
    sort(data, data + size);
    if (size % 2 == 0) {
        return static_cast<double>(data[size / 2 - 1] + data[size / 2]) / 2;
    } else {
        return static_cast<double>(data[size / 2]);
    }
}

// Function to compute the mode of the survey data
int computeMode(int data[], int size) {
    int freq[MAX_SIZE] = {0};
    for (int i = 0; i < size; i++) {
        freq[data[i]]++;
    }
    int max_freq = 0;
    int mode = 0;
    for (int i = 0; i < MAX_SIZE; i++) {
        if (freq[i] > max_freq) {
            max_freq = freq[i];
            mode = i;
        }
    }
    return mode;
}

int main() {
    int data[MAX_SIZE];
    int size;
    cout << "Enter the number of survey data: ";
    cin >> size;
    cout << "Enter the survey data: ";
    for (int i = 0; i < size; i++) {
        cin >> data[i];
    }
    double mean = computeMean(data, size);
    double median = computeMedian(data, size);
    int mode = computeMode(data, size);
    cout << "Mean: " << mean << endl;
    cout << "Median: " << median << endl;
    cout << "Mode: " << mode << endl;
    return 0;
}
