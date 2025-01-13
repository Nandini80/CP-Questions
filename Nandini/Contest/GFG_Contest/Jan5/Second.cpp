#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    bool isPossible(vector<int> &arr) {
        map<int,int> mp;
        int n = arr.size();
        for(int i=0 ; i<n ;i ++) mp[arr[i]] = i;
        
        stack<pair<int,int> > st;
        for(int i=0 ; i<n ; i++){
            
            if(!st.empty() && st.top().first<mp[arr[i]]) return false;
            if(mp[arr[i]]!=i){
                st.push({mp[arr[i]],arr[i]}); // lastind. val
            }
            else {
                while(!st.empty() && st.top().first==mp[arr[i]]) st.pop();
            }
        }
        return true;
    }
};
