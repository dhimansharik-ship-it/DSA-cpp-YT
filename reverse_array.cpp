// Reverse a given array
// 2-pointer approach
#include <iostream>
using namespace std;
int main() {
    // Initialize the array
    int arr[] = {12, 55, 4, 37, 8};
    int size = 5;
    cout << "Normal  array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout<<endl;
    // Initialize two pointers
    int start = 0;
    int end = size - 1;
    // Swap elements until both pointers meet
    while (start < end) {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    // Print the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}