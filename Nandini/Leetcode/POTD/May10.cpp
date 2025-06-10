#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxDifference(string s) {
        vector<int> v(26,0);
        for(auto it : s){
            v[it-'a']++;
        }

        int mini =1e9, maxi=-1e9;
        for(int i=0 ; i<26 ;i ++){
            if(!v[i]) continue;
            if(v[i]%2==0)
            mini = min(mini,v[i]);
            else maxi = max(maxi,v[i]);
        }
        return maxi-mini;
    }
};