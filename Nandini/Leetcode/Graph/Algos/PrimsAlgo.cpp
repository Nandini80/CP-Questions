#include <bits/stdc++.h>
using namespace std;
class Solution
{
	public:
    int spanningTree(int V, vector<vector<int>> adj[])
    {
       priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > pq;
       pq.push({0,0});
       vector<int> vis(V,0);
       int sum =0;
       while(!pq.empty())
       {
           int wt = pq.top().first;
           int node = pq.top().second;
           pq.pop();
           
           if(vis[node]) continue;
            vis[node] = 1;
            sum+=wt;
           for(auto it : adj[node])
           {
               int n = it[0];
               int edgesWt = it[1];
               if(vis[n]) continue;
               pq.push({edgesWt,n});
           }
       }
       return sum ;
    }
};