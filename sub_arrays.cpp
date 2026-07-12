#include <iostream>
using namespace std;
//print all the sub arrays
int main() {
    int n = 5;
    int arr[] = {1, 2, 3, 4, 5};

    for (int str = 0; str < n; str++) {
        for (int end = str; end < n; end++) {
            for (int i = str; i <= end; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}