int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto x:nums)
            m[x]=1;
        int res=0;
        for(auto x:m)
        {
            int t=x.first-1;
            if(m.find(t)==m.end())
            {
                int curr=x.first+1;
                int c=1;
                while(m.find(curr)!=m.end())
                {
                    curr++;
                    c++;
                }
                //cout<<x.first<<c<<endl;
                res=max(res,c);
            }
        }
        return res;
 }
 int main()
 {
    vector<int> v{100,4,200,1,3,2};
    cout<<longestConsecutive(v)<<endl;
 }
