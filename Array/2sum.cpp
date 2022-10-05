#include <bits/stdc++.h>

using namespace std;

int main(){


    vector<int> nums={2,7,11,15};
    int target=9;
        unordered_map<int,int> mp;
        
        int fg=0;
        for(int i=0;i<nums.size();i++)
        {
            
           if(mp.find(target-nums[i])!=mp.end()) 
           {cout<<mp[target-nums[i]]<<i<<endl;
              fg=1;    
            break;}
               
               mp[nums[i]]=i;
        }
        
              if(fg==0)
                cout<<-1<<" "<<-1<<endl;
  
  return 0;
       
  
  
}
