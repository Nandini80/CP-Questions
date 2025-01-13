#include <bits/stdc++.h>
using namespace std;
// what we will do is bs ki help se haar weight ke liye dekhege ki yeh ho sakta hai max ya nhi agr yes toh kaam values pr check karege nhi toh jada pr
class Solution {
    void dfs(vector<pair<int,int>>adj[], vector<bool> &vis,int node,int maxi){
        vis[node] = true;
        for(auto it : adj[node]){
            if(!vis[it.first] && it.second<=maxi)
            dfs(adj,vis,it.first,maxi);
        }
    } 
public:
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<pair<int,int> > adj[n];
        // making reverse graph because we want to check ki sab edges pr 0 se ja paye
        int maxi =-1;
        for(auto it : edges) {
            adj[it[1]].push_back({it[0],it[2]});
            maxi = max(maxi,it[2]);
        }

        int ans =-1,s=1,e=maxi;
        while(s<=e){
            int m = (s+e)>>1;

            vector<bool> vis(n,false);
            dfs(adj,vis,0,m);
            bool isPos = true;
            for(int i=0 ;i <n ;i ++) if(!vis[i]) isPos = false;
            if(isPos){
                e = m-1;
                ans = m;
            }
            else s = m+1;
        }
        return ans;
    }
};