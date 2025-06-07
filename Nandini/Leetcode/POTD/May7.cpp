#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string clearStars(string s) {
        vector<stack<int> > count(26);
        int n = s.size();
        vector<int> v(n,0); // mark the index as 1 which are not in the soln
        for(int i=0 ; i<n ; i++){
            if(s[i]!='*'){
                count[s[i]-'a'].push(i);
            }
            else{
                v[i] = 1;
                for(int j=0 ; j<26 ; j++){
                    if(!count[j].empty()){
                        v[count[j].top()] = 1;
                        count[j].pop();
                        break;  
                    }
                }
            }
        }

        string ans ="";
        for(int i=0 ;i <n ;i ++){
            if(!v[i]) ans+=s[i];
        }
        return ans;
    }
};