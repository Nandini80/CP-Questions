#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int> > v;
        for(int i=0 ; i<nums.size() ; i++){
            v.push_back({nums[i],i});
        }
        sort(v.begin(),v.end());
        vector<pair<int,int> > val;
        for(int i=v.size()-1 ; i>=0 && k>0 ; i--){
          val.push_back({v[i].second,v[i].first});
          k--;
        }
        sort(val.begin(),val.end());
        vector<int> ans;
        for(auto it : val){
            ans.push_back(it.second);
        }
        return ans;
    }
};