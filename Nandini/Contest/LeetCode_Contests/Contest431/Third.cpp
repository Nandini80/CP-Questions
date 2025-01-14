#include<bits/stdc++.h>
using namespace std;
#define ll long long
class Solution {
public:
static bool cmp(vector<int> &a,vector<int> &b){
      return a[0]<b[0];
    }
    long long maximumCoins(vector<vector<int>>& coins, int k) {
        ll ans = 0, n = coins.size();
       sort(coins.begin(),coins.end(),cmp);
       ll j=0, curr=0;
       for(int i=0 ;i <n ; i++)
       {
           while(j<n && coins[j][1]<=coins[i][0]+k-1){
            curr += ((ll)coins[j][1]-coins[j][0]+1)*((ll)coins[j][2]);
            j++;
           }

           ll extra =0;
           if(j<n && coins[i][0]+k-1 >= coins[j][0]){
            extra += ((ll)coins[i][0]+k-coins[j][0])*((ll)coins[j][2]);
           }
           ans = max(ans,curr+extra);
           curr-= ((ll)coins[i][1]-coins[i][0]+1)*(ll)coins[i][2];
       }
       j=n-1,curr=0;
        for(int i=n-1 ;i >=0 ; i--)
         {
           while(j>=0 && coins[j][0]>=coins[i][1]-k+1){
            curr += ((ll)coins[j][1]-coins[j][0]+1)*((ll)coins[j][2]);
            j--;
           }

           ll extra =0;
           if(j>=0 && coins[i][0]-k+1 <= coins[j][1]){
            extra += ((ll)coins[j][1]+k-coins[i][1])*((ll)coins[j][2]);
           }
           ans = max(ans,curr+extra);
           curr-= ((ll)coins[i][1]-coins[i][0]+1)*(ll)coins[i][2];
       }
       return ans;

    }
};