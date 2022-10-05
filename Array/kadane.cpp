#include<bits/stdc++.h>
using namespace std;


// !------

// Time Complexity: O(N)
// Space complexity: O(1)

// -------!


// arr: input array
// n: size of array
//Function to find the sum of contiguous subarray with maximum sum.
long long maxSubarraySum(int arr[], int n){

    long long temp=0;
    long long curr=INT_MIN;

    // temp stores the maximum sum contiguous subarray ending at current index
    // curr stores the maximum sum of contiguous subarray found so far
    for(int i=0;i<n;i++){
        temp=temp+arr[i];
        if(temp>curr){
            curr=temp;
        }
        if(temp<0){
            temp=0;
        }
    }
    return curr;
    
}


int main(){
    int n;
    printf("Enter number of elements: ");
    cin>>n;
    int arr[n];
    printf("Enter array elements: ");
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    printf("Maximum continous subarray sum is: ");
    cout<<maxSubarraySum(arr,n)<<endl;

}

