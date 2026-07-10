#include <iostream>
using namespace std;

// Function to perform linear search
int Linear_Search(int arr[], int size, int target) {

    // Traverse the array one element at a time
    for (int i = 0; i < size; i++) {

        // Check if the current element matches the target
        if (arr[i] == target) {
            return i;      // Return the index if target is found
        }
    }

    // Return -1 if the target is not present in the array
    return -1;
}

int main() {

    // Declare and initialize the array
    int arr[] = {23, 5, 67, 0, 99};
    int size = 5;

    // Element to be searched
    int target = 0;

    // Call the linear search function
    int index = Linear_Search(arr, size, target);

    // Display the result
    if (index != -1) {
        cout << "Target found at index: " << index << endl;
    } else {
        cout << "Target not found." << endl;
    }

    return 0;
}