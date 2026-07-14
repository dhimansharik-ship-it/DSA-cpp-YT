#include <iostream>
using namespace std;

int main() {
    int arr[] = {1, 3, 21, 54};  
    int target = 24;

    int size = 4;
    int start = 0;
    int end = size - 1;

    while (start < end) {
        int pairSum = arr[start] + arr[end];

        if (pairSum > target) {
            end--;
        }
        else if (pairSum < target) {
            start++;
        }
        else {
            cout << "The target pair is at indices "
                 << start << " and " << end << endl;
            break;
        }
    }

    return 0;
}