#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(int i,int j,vector<vector<int> > &vis,vector<vector<char> > &grid){
            vis[i][j] = 1;
            int drow[4] = {-1,0,1,0};
            int dcol[4] = {0,1,0,-1};
            for(int itr=0; itr<4 ; itr++){
                int nr = drow[itr]+i,nc = dcol[itr]+j;
                if(nr>=0 && nc>=0 && nr<grid.size() && nc<grid[0].size() && !vis[nr][nc] && grid[nr][nc]=='1')
                dfs(nr,nc,vis,grid);
            }
        }
        int numIslands(vector<vector<char>>& grid) {
            int ans=0,n = grid.size(),m = grid[0].size();
            vector<vector<int> > vis(n,vector<int> (m,0));
            for(int i=0 ; i<n ;i++){
                for(int j=0 ; j<m ;j++){
                    if(!vis[i][j] && grid[i][j]=='1'){
                         dfs(i,j,vis,grid);
                         ans++;
                    }
                }
            }
            return ans;
        }
    };