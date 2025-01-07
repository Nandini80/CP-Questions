#define ll long long
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long calculateScore(string s) {
        // val, ind,count
        map<ll,pair<stack<ll> ,ll> > mp;
        ll n = s.size(), ans=0;
        for(ll i=0 ; i<n ; i++)
        {
            int val = 25-(s[i]-'a');
            // cout << "s=" << s[i] << endl;
            // cout << "val=" << val << ", word=" << s[i]-'a' << endl;
            if(mp[val].first.size()==0)
            {
                val = s[i]-'a';
                if(mp[val].second==0)
                {
                    mp[val] = {{}, 1};
                    mp[val].first.push(i);

                }
                else {
                    mp[val].second++;
                    mp[val].first.push(i);
                }
            }
            else{
                // cout << "Here\n";
                ans+= (i-mp[val].first.top());
                // cout << (i-mp[val].first.top()) <<  endl;
                mp[val].first.pop();
                mp[val].second--;
            }
        }
        return ans;
    }
};