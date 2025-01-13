#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins) {
        int n = coins.size(),m = coins[0].size();
        // x,y, kitne neg skip kiye
        vector<vector<vector<int> > > dp(n+1,vector<vector<int> > (m+1,vector<int>(3,INT_MIN)));
        
        dp[0][1][0] = dp[0][1][1] = dp[0][1][2] = dp[1][0][0] = dp[1][0][1] = dp[1][0][2] =0;
        for(int i=1 ;i <=n ; i++){
            for(int j=1 ;j <=m ; j++){
                for(int k=0 ; k<=2 ; k++)
                {
                    dp[i][j][k] = max(dp[i-1][j][k],dp[i][j-1][k]) + coins[i-1][j-1];
                    if(k>0){
                        dp[i][j][k] = max(dp[i][j][k],max(dp[i][j-1][k-1],dp[i-1][j][k-1]));
                    }
                }
            }
        }
        return dp[n][m][2];

    }
};