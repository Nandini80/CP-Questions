#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(int ans,vector<int> &nums,int p){
        int i=0;
        while(i<nums.size()-1){
            if(abs(nums[i]-nums[i+1])<=ans){
                p--;
                i+=2;
            }
            else i++;
        }
        return p<=0;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int n = nums.size(), ans=-1;
        int s=0,e = nums[n-1]; // ans can be 0 to largest value
        while(s<=e){
            int mid = (s+e)>>1;
            if(isPossible(mid,nums,p)){
                ans= mid;
                e = mid-1;
            }
            else s= mid+1;
        }
        return ans;
    }
};