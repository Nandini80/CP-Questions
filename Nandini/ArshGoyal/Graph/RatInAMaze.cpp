#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
      void findAll(vector<vector<int>> &mat,vector<string> &ans,vector<vector<int>> &vis,int n,int r,int c,string path){
          if(r==n-1 && c==n-1){
              ans.push_back(path); return;
          }
          
          vis[r][c] = 1;
          
          int drow[4] = {-1,0,1,0};
          int dcol[4] = {0,1,0,-1};
          vector<char> add = {'U','R','D','L'};
          for(int itr=0; itr<4 ; itr++){
              int nr = drow[itr]+r,nc = dcol[itr]+c;
              if(nr>=0 && nc>=0 && nr<n && nc<n && mat[nr][nc]==1 && !vis[nr][nc])
                  {
                      findAll(mat,ans,vis,n,nr,nc,path+add[itr]);
                  }
          }
          vis[r][c] = 0;
      }
      vector<string> findPath(vector<vector<int>> &mat) {
          int n = mat.size();
          vector<string> ans;
          vector<vector<int> > vis(n,vector<int> (n,0));
          findAll(mat,ans,vis,n,0,0,"");
          return ans;
      }
  };