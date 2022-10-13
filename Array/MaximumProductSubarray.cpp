#include<bits/stdc++.h>
int maxProduct(vector<int>& nums) {
        int p=nums[0],q=nums[0],t=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            int temp=max(nums[i],max(nums[i]*p,nums[i]*q));
            q=min(nums[i],min(nums[i]*q,nums[i]*p));
            p=temp;
            t=max(t,max(p,q));
        }
        return t;
}
int main()
{
    vector<int> v{-2,0,-1};
    cout<<maxProduct(v)<<endl;
}
