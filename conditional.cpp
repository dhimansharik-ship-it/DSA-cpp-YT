#include <iostream>
using namespace std;

int main() {
    cout<<"enter a char to check"<<endl;
  char ch;
cin >> ch;

if (ch >= 97 && ch <= 122) {
    cout << "Lower case";
}
else if (ch >= 65 && ch <= 90) {
    cout << "Upper case";
}
else {
    cout << "Not an alphabet";
}
    return 0;
}