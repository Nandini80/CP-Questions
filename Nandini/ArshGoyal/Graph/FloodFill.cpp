#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        void dfs(vector<vector<int>>& image, int sr, int sc,int chk, int color,vector<vector<int>>& vis){
            vis[sr][sc] = 1;
            image[sr][sc] = color;
            int drow[4] = {-1,0,1,0};
            int dcol[4] = {0,1,0,-1};
            for(int itr=0; itr<4 ; itr++){
                int nr = drow[itr]+sr,nc = dcol[itr]+sc;
                if(nr>=0 && nc>=0 && nr<image.size() && nc<image[0].size() && image[nr][nc]==chk && !vis[nr][nc])
                    dfs(image,nr,nc,chk,color,vis);
                }
        }
        vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)  {
            vector<vector<int> > vis(image.size(),vector<int> (image[0].size(),0));
            dfs(image,sr,sc,image[sr][sc],color,vis);
            return image;
        }
    };