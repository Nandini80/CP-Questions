#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(),val=0;
        map<int,set<char> > mp;
        vector<int> v(26,-1);
        for(int i=0 ;i <n ; i++){
            if(v[s1[i]-'a']==-1 && v[s2[i]-'a']==-1){
                mp[val].insert(s1[i]);
                mp[val].insert(s2[i]);
                v[s1[i]-'a'] = val;
                v[s2[i]-'a'] = val;
                val++;
            }
            else {
                int a = v[s1[i]-'a'];
                int b = v[s2[i]-'a'];
                if(a!=-1 && b!=-1){
                    mp[a].insert(mp[b].begin(), mp[b].end());
                    for (char ch : mp[b]) v[ch - 'a'] = a;
                } 
                else if(a!=-1){
                  mp[a].insert(s2[i]);
                  mp[a].insert(s1[i]);
                  v[s2[i]-'a'] = a;
                }
                else {
                    
                    mp[b].insert(s1[i]);
                    mp[b].insert(s2[i]);
                    v[s1[i]-'a'] = b;
                }
            }
        }

        string ans = ""; 
        for(auto it : baseStr){
            val = v[it-'a'];
            // cout << "For : " << it << endl;
            if(val!=-1)
            {
                // for(auto it : mp[val]) cout << it << " ";
                // cout << endl;
                ans += *mp[val].begin();
            }
            else ans+= it;
        }
        return ans;
    }
};