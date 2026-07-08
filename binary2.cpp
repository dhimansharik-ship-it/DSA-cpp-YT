#include <iostream>
using namespace std;

int main() {
    int ans = 0;
    int num;
    int pow = 1;

    cout << "Enter binary number to be converted into decimal: ";
    cin >> num;

    while (num > 0) {
        int rem = num % 10;
        ans += rem * pow;
        num = num / 10;
        pow *= 2;
    }

    cout << ans << endl;

    return 0;
}