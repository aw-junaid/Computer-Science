#include <iostream>

using namespace std;

int main() {
    int num = 5, pre, post;

    // pre-increment
    pre = ++num;
    cout << "The value of num after pre-incrementing: " << num << endl;
    cout << "The value of pre after pre-incrementing: " << pre << endl;

    num = 5; // resetting num to its initial value

    // post-increment
    post = num++;
    cout << "The value of num after post-incrementing: " << num << endl;
    cout << "The value of post after post-incrementing: " << post << endl;

    return 0;
}
