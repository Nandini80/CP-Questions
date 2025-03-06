#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      bool dfs(vector<vector<int>>& adj,vector<int> &parent,vector<int> &vis,int n,int node){
          vis[node] = 1;
          for(auto nbr : adj[node]){
              if(!vis[nbr]) {
                  parent[nbr] = node;
                  if(dfs(adj,parent,vis,n,nbr)) return true;
              }
              
              else if(vis[nbr] && parent[node]!=nbr) return true;
          }
          return false;
      }
      bool isCycle(vector<vector<int>>& adj) {
          int n = adj.size();
          vector<int> parent(n,-1),vis(n,0);
          for(int i=0 ; i<n ;i ++){
              if(!vis[i]){
                  if(dfs(adj,parent,vis,n,i)) return true;
              }
          }
          return false;
          
      }
  };