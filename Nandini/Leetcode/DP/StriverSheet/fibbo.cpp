#include<bits/stdc++.h>
using namespace std;
int fibbo(int n,vector<int> &dp)
{
        if(n==0 || n==1)return n;
        if(dp[n]!=-1) return dp[n];

        return dp[n] = fibbo(n-1,dp)+fibbo(n-2,dp);
}
int main()
{
        int n;
        cin >> n;
        vector<int> dp(n+1,-1);
        cout << fibbo(n,dp);
}