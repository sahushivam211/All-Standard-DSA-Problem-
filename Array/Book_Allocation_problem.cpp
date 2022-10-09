#include<bits/stdc++.h>
using namespace std;

int isPossible(vector < int > & A, int pages, int students) {
  int cnt = 0;
  int sumAllocated = 0;
  for (int i = 0; i < A.size(); i++) 
  {
    if (sumAllocated + A[i] > pages) 
    {
      cnt++;
      sumAllocated = A[i];

      if (sumAllocated > pages) 
         return false;
    } 
    else 
    {
      sumAllocated += A[i];
    }
  }
  if (cnt < students) 
      return true;

  return false;
}
int allocateBook(vector < int > & A, int B) {
  if (B > A.size()) return -1;
  
  int low = A[0];
  
  int high = 0;

  // Find the minimum value along with sum of all pages

  for (int i = 0; i < A.size(); i++) 
  {
    high = high + A[i];
    low = min(low, A[i]);
  }
// Just do normal Binary Search ::::
  while (low <= high) {
    int mid = (low + high)/2;;
    if (isPossible(A, mid, B)) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
}
int main() {
  vector<int>  arr= {12,34,67,90};  // pages of book

  int k = 2;  // number of students
  
  cout << "Minimum Possible Number is " << allocateBook(arr, k);
  return 0;
}
