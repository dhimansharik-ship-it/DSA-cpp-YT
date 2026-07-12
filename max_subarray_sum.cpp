#include <iostream>
using namespace std;
//max subarray sum using brute force approach 
int main (){
 int n = 5;
    int arr[] = {1, 32, 3, -84, 5};
    int maxSum=0;
    for (int str = 0; str < n; str++) {
        int currSum=0;
        for (int end = str; end < n; end++) {
        currSum  += arr[end];
        maxSum = max(currSum,maxSum);
        }
    }
 cout<<maxSum<<endl;
    return 0;

}