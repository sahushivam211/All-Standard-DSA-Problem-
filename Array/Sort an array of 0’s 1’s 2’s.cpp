#include <bits/stdc++.h>
using namespace std;

int main() {
    // taking input of number of elements in array
    int n;
    cin>>n;

    // taking input of array
    int array[n];
    for(int i =0;i<n;i++){
        cin>>array[i];
    }

    // sorting array using sort function
    // synatx of sort function --> sort(start,end)

    sort(array,array+n);

    // displaying the sorted array
    for(int i =0;i<n;i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;

    return 0;
}
