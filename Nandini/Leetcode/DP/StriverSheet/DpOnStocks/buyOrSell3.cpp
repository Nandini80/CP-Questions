#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int f(int ind,int buy,int cap,vector<int> &arr,vector<vector<vector<int> > > &dp,int n)
    {
    if(cap==0) return 0;
    if(ind==n) return 0;

    if(dp[ind][buy][cap] !=-1) return dp[ind][buy][cap] ;

    if(buy)
    {
        return dp[ind][buy][cap] = max(-arr[ind]+f(ind+1,0,cap,arr,dp,n),f(ind+1,1,cap,arr,dp,n));
    }
    else 
    return dp[ind][buy][cap] = max(arr[ind]+f(ind+1,1,cap-1,arr,dp,n),f(ind+1,0,cap,arr,dp,n));
    }
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
    vector<vector<vector<int> > > dp(n,vector<vector<int> > (2,vector<int> (3,-1)));
    return f(0,1,2,prices,dp,n);
    }
};