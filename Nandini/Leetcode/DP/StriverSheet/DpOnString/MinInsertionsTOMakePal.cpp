#include <bits/stdc++.h>
using namespace std;
int minimumInsertions(string &s)
{
	 string t = s;
    reverse(t.begin(),t.end());
        int n1 = s.size(),n2 = t.size();
        vector<vector<int> > dp(n1+1,vector<int> (n2+1,-1));
       for(int i=0 ;i <=n1 ; i++)
           dp[i][0] = 0;
        
        for(int j=0 ;j <=n2 ; j++)
           dp[0][j] = 0;
        
        for(int i=1 ;i<=n1 ; i++)
        {
            for(int j=1 ; j<=n2 ; j++)
            {
                if(s[i-1]==t[j-1])  dp[i][j] = 1+ dp[i-1][j-1];

                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        
        return s.size()- dp[n1][n2];
}
