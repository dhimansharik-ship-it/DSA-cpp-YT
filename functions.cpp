#include <iostream>
using namespace std;

int sumN(int n ){
    int sum = 0;
    for(int i=0;i<n;i++){
        sum = sum+i;

    }
    return sum;
}
int main(){
    int n;
cout<<"enter till which number you want the sum:  "<<endl;
cin>>n;
cout<<sumN(n);

    return 0;
}