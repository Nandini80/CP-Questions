#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        int maxProduct(vector<int>& nums) {
            int pref=1,suff=1,ans=INT_MIN;
            for(auto it : nums){
                pref*=it;
                ans = max(ans,pref);
                if(pref==0) pref=1;
            }
            for(int i=nums.size()-1 ; i>=0 ;i--){
                suff*=nums[i];
                ans = max(ans,suff);
                if(suff==0) suff=1;
            }
            return ans;
        }
    };