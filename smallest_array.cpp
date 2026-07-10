#include <iostream>
#include <limits.h>
using namespace std;
int main(){
int arr[]={12,68,-33,6,20};
int size=5;
int smallest=INT_MAX;
for(int i=0;i<size;i++){
 if(arr[i]<smallest){
    smallest=arr[i];
 }
}
cout<<smallest<<endl;




}