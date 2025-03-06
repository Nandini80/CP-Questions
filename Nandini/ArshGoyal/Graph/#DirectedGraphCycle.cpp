#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      bool dfs(vector<vector<int> > &adj,vector<int> &vis,int n,int node,vector<int> &restack){
          vis[node] =1 ;
          restack[node] = 1;
          for(auto it : adj[node]){
              if(!vis[it]){
                  if(dfs(adj,vis,n,it,restack)) return true;
              }
              else if(restack[it]){
                  return true;
              }
          }
          restack[node] = 0;
          return false;
      }
      bool isCyclic(vector<vector<int>> &adj) {
         int n = adj.size();
         vector<int> vis(n,0),restack(n,0);
         for(int i=0 ; i<n ;i ++){
             if(dfs(adj,vis,n,i,restack)) return true;
         }
         return false;
      }
  };