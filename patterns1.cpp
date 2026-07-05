#include <iostream>
using namespace std;
int main(){
    cout<<"pattern 1.)"<<endl;

int a = 4;
for(int b = 1; b<=a; b++){
    for(int c = 1; c<=a ; c++){
                cout<<c;
    }
cout<<endl;
}

cout<<endl;
cout<<"pattern 2.)"<<endl;
int n = 3;
int k=0;
for(int i = 1; i<=n; i++){
    for(int j = 1; j<=n ; j++){
                cout<<k;
                k++;
    }

cout<<endl;
}
cout<<endl;

cout<<"pattern 3.)"<<endl;
int x = 4;
for(int y  = 0; y<=x; y++){
    for(int z = 1; z<=y+1; z++){
                cout<<"*";
                
                
    }

cout<<endl;
}
cout<<endl;






    return 0 ;
}