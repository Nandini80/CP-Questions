#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        set<int> ans;
        int n = nums.size();
        for(int i=0 ;i <n ; i++){
            if(nums[i]==key){
                for(int j=max(0,i-k) ; j<=min(n-1,i+k) ; j++) ans.insert(j);
            }
        }
        vector<int> finall;
        for(auto it : ans) finall.push_back(it);
        return finall;
    }
};