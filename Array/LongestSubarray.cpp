#include<bits/stdc++.h>
int maxLen(vector<int>& A, int n)
{
    unordered_map<int,int> mp; 
    int m = 0;
    int sum = 0; 
    for(int i = 0;i<n;i++) {
        sum += A[i]; 
        if(sum == 0)
            m = i + 1; 
        else {
            if(mp.find(sum) != mp.end()) {
                m = max(m, i - mp[sum]); 
            }
            else {
                mp[sum] = i;
            }
        }   
    }
    return m; 
}
int main()
{
    vector<int> v{1, 2, -2, 4, -4};
    cout<<maxLen(v,v.size())<<endl;
}
