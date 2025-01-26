#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int longestPalindrome(vector<int>& v) {
        int n = v.size();
        vector<long long> arr ;
        for(auto it : v)arr.push_back(it);
        int s=0,e=n-1,ans=0;
        while(s<=e){
            if(arr[s]==arr[e]){
                ans+=s!=e?2:1;
                s++,e--;
            }
            else if(arr[s]<arr[e]){
                arr[s+1]+= arr[s];
                s++;
            }
            else {
                arr[e-1]+=arr[e];
                e--;
            }
        }
        return ans;
    }
};
