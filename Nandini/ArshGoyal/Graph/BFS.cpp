#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfsOfGraph(vector<vector<int>> &adj) {
          int n = adj.size();
          vector<int> ans,vis(n,0);
          queue<int> q;
          q.push(0);
          vis[0] = 1;
          while(!q.empty()){
              int node = q.front(); q.pop();
              ans.push_back(node);
              for(auto it : adj[node]){
                  if(!vis[it]){
                      q.push(it);
                      vis[it] = 1;
                  }
              }
          }
          return ans;
      }
  };