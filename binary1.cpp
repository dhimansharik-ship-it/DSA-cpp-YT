#include <iostream>
using namespace std;
int main(){
int ans=0;
int num;
int pow=1;
cout<<"Enter the number to be converted to binary: "<<endl;
cin>>num;
while(num>0){
    int rem=num%2;
    num=num/2;
    ans+=(pow*rem);
    pow=pow*10;
}
cout<<ans;
    return 0;
}