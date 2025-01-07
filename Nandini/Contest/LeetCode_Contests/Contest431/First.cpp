#include <bits/stdc++.h>

using namespace std;
class Solution {
public:
    int maxLength(vector<int>& nums) {
       int n = nums.size(),j,ans=0;
       for(int i=0 ;i<n ;i++)  
       {
         int gcdd = nums[i], lcmm = nums[i];
         long long pdt = nums[i];
         for( j=i+1 ; j<n ; j++)
         {
            gcdd = __gcd(gcdd,nums[j]);
            lcmm = lcm(lcmm,nums[j]);
            pdt = pdt*nums[j];
            // cout << "lcm=" << lcmm << ",gcd=" << gcdd << ",pdt=" << pdt << endl;
            if(pdt!=(long long)gcdd*lcmm) break;
         }
         ans = max(ans,j-i);
       } 
       return ans;
    }
};