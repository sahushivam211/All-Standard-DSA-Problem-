
// !----- 

// Time Complexity: O(N*log N)
// Space Complexity: O(N)

// ------!


#include<bits/stdc++.h>
using namespace std;

// function to merge two sorted array.
void merge(int arr[], int low, int mid, int high){
	int i,j,k,n1,n2;
	n1 = mid-low+1;
	n2 = high-mid;

	// using temporary arrays to store elements.
	int left[n1],right[n2];
	for(i=0;i<n1;i++){
		left[i] = arr[low+i];
	}
	for(j=0;j<n2;j++){
		right[j] = arr[mid+1+j];
	}

	i=0,j=0,k=low;
	// pushing elements into result array
	while(i<n1 && j<n2){
		if(left[i] <= right[j]){
			arr[k] = left[i];
			i++;
		}
		else{
			arr[k] = right[j];
			j++;
		}
		k++;
	}

	while(i<n1){
		arr[k] = left[i];
		i++;k++;
	}
	while(j<n2){
		arr[k] = right[j];
		j++;k++;
	}
}


// divide and conquer approach
void sort(int arr[], int low, int high){
	int mid;

	// recursively cal sort function with updated parameters.
	if(low < high){
		mid = low + (high-low)/2;
		sort(arr,low,mid);
		sort(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}


int main(){
	int n;
	printf("Enter number of elements: ");
	cin >> n;
	int arr[n];
	printf("Enter array elements: ");
	for(int i=0;i<n;i++)
		cin >> arr[i];

	// calling merge sort function.
	sort(arr,0,n-1);

	for(int i=0;i<n;i++)
		cout << arr[i] << " ";
	cout << endl;
	return 0;
}
