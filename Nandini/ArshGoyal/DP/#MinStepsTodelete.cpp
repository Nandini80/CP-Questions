#include<bits/stdc++.h>
using namespace std;
class Solution{
    int dp[1001][1001];
    int fn(int i,int j,string& s){
        if(i==j) return 1;
        if(i>j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans = 1+min(fn(i+1,j,s),fn(i,j-1,s)); 
        for(int k=i+1 ; k<=j ;k++){
            if(s[i]==s[k]){
                ans = min(ans,max(1,fn(i+1,k-1,s)) + fn(k+1,j,s));
            }
        }
        return dp[i][j] = ans;
    }
	public:
	int minStepToDeleteString(string s) 
	{ 
	    int n = s.size();
	    for(int i=0 ; i<n ;i++){
	        for(int j=0 ; j<n ; j++) dp[i][j]=-1;
	    }
	    return fn(0,n-1,s);
	} 
};
