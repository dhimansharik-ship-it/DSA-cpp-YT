#include <iostream>
using namespace std;

void changeA(int *ptr){
    *ptr = 20;
}

int main(){
    int a = 10;

    changeA(&a);

    cout << "value of a in main fxn = " << a << endl;

    return 0;
}