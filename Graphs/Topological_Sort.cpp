#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Time Complexity: O(N+E) 

N = Number of node , E = Number of Edges

Space Complexity: O(N) + O(N)

Visited Array and Stack data structure. Both will be using O(N).

*/
void DFS(int i,vector<int> adj[],vector<int>&vis,stack<int>&st){
	    
	    vis[i] = 1;
	    
	    for(auto x : adj[i]){
	        
	        if(!vis[x]){
	            DFS(x,adj,vis,st);
	        }
	    }
	    
	    // DFS call is over so push i in the stack
	    st.push(i);
	    
	}
vector<int> solveDFS(int V, vector<int>adj[]){
	   
	   vector<int>ans;
	   vector<int>vis(V,0);
	   stack<int>st;
	   for(int i = 0;i<V;i++){
	       
	       if(!vis[i]){
	           DFS(i,adj,vis,st);
	       }
	   }
	   
	   while(!st.empty()){
	       
	       ans.push_back(st.top());
	       st.pop();
	   }
	   
	   return ans;
	}
vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    
	   //return solveDFS(V,adj) ; 
       
       
       return solveDFS(V,adj) ; // KAHN's Algo 
	   

	   
	}     
int main()
{
   int V = 6;  // vertices in graph

  vector < int > adj[V + 1];

  adj[5].push_back(2);
  adj[5].push_back(0);
  adj[4].push_back(0);
  adj[4].push_back(1);
  adj[2].push_back(3);
  adj[3].push_back(1);

  vector<int>topo = topoSort(V,adj);
  cout<<"topological sort below\n" ;
  for(auto x : topo)
    cout<<x<<endl;

 
 return 0;
}
