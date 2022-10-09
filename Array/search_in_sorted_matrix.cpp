#include<iostream>
#include<bits/stdc++.h>
using namespace std;
 
bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row = matrix.size();
        int col = matrix[0].size();
        int start = 0;
        int end = row * col - 1;
        
        int mid = start + (end - start)/2;  // finding middle
        
        while(start<=end)
        {  
            int r = mid/col;  // row number
            int c = mid % col; // column number
            
            if(matrix[r][c] == target)
                return true;
            else if(matrix[r][c] > target)
            {
                end = mid - 1;
            }
            else if (matrix[r][c] < target)
            {
                start = mid + 1;
            }
           
         mid =  start + (end - start)/2; 
        }
        return false;
    }
int main()
{
 
 vector<vector<int>>matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}} ;
 int target = 16;

 searchMatrix(matrix,target)?cout<<"Yes target is present\n":cout<<"Target not found\n";
 
 return 0;
}
