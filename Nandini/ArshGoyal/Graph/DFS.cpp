#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      // Function to return a list containing the DFS traversal of the graph.
      void dfs(int node,vector<vector<int> > &adj,vector<int> &ans,int n,vector<int> &vis){
          vis[node] = 1;
          ans.push_back(node);
          for(auto it : adj[node]){
              if(!vis[it])
              dfs(it,adj,ans,n,vis);
          }
      }
      vector<int> dfsOfGraph(vector<vector<int>>& adj) {
          int n = adj.size();
         vector<int> ans,vis(n,0);
         dfs(0,adj,ans,n,vis);
         return ans;
      }
  };