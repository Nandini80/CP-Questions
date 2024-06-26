#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long f(int i,int j,int isTrue,string &a,vector<vector<vector<int> > >&dp)
{
    if(i>j) return 0;
    if(i==j)
    {
        if(isTrue) return a[i]=='T';
        else return a[i]=='F';
    }
    if(dp[i][j][isTrue]!=-1) return dp[i][j][isTrue];

    long long ways =0;
    for(int ind=i+1 ; ind<j ; ind+=2)
    {
         long long LT = f(i,ind-1,1,a,dp);
         long long RT= f(ind+1,j,1,a,dp);
         long long LF = f(i,ind-1,0,a,dp);
         long long RF = f(ind+1,j,0,a,dp);

        if(a[ind]=='&')
        {
            if(isTrue) ways = (ways+(LT*RT)%mod)%mod;
            else ways =(ways + (LF*RF)%mod + (LF*RT)%mod + (LT*RF)%mod)%mod;
        }
        else if(a[ind]=='|') 
        {
            if(isTrue) ways = (ways+ (LT*RF)%mod + (LT*RT)%mod + (LF*RT)%mod)%mod;
            else ways = (ways+ (LF*RF)%mod)%mod;
        }
        else 
        {
            if(isTrue) ways = (ways+ (LT*RF)%mod + (LF*RT)%mod)%mod;
            else ways = (ways+ (LT*RT)%mod +(LF*RF)%mod)%mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string & exp) 
{
    int n = exp.size();
    vector<vector<vector<int> > > dp(n,vector<vector<int> > (n,vector<int> (2,-1)));
    return f(0,n-1,1,exp,dp);
}