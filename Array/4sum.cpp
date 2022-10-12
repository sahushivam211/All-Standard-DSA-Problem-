#include<bits/stdc++.h>
using namespace std;
void Sort_4sum(int nums[], int n, int X)
{
    int l, r;
    sort(nums, nums+n);
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i+1; j < n - 2; j++)
        {
            l = j + 1;
            r = n-1;         
            while (l < r)
            {
                if( nums[i] + nums[j] + nums[l] + nums[r] == X)
                {
                    cout <<"["<< nums[i]<<", " << nums[j] <<
                        ", " << nums[l] << ", " << nums[r]<<"]"<<endl;
                    l++; r--;
                }
                else if (nums[i] + nums[j] + nums[l] + nums[r] < X)
                    l++;
                else
                    r--;
            } 
        } 
    } 
}
int main()
{
    int nums[] = {10, 2, 3, 4, 5, 9, 7, 8} ;
    int n = sizeof(nums) / sizeof(nums[0]);
    int target = 23;
    Sort_4sum(nums, n, target);
    return 0;
}