#include <iostream>
using namespace std;

int main() {
    int n = 4;

    for(int i = 0; i < n; i++) {

        // Left spaces
        for(int k = 0; k < i; k++) {
            cout << " ";
        }

        // Numbers
        for(int j = n - i; j > 0; j--) {
            cout << i + 1;
        }

        cout << endl;
    }

    return 0;
}