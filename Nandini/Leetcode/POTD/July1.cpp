#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1,count=0;
        for(int i=1 ; i<word.size() ; i++){
            if(word[i]==word[i-1]){
                count++;
            }
            else {
                ans += count;
                count=0;
            }
        }
        ans+=count;
        return ans;
    }
};