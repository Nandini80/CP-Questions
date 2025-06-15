#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(int n,int x,int y){
        // x to y
        string s= to_string(n);
        for(auto &c: s){
            if(c-'0'==x){
               c = y+'0'; 
            }
        }
        return s;
    }
    int maxDiff(int num) {
        int mini = num, maxi = num;
        for(int x=0 ; x<10 ; x++){
            for(int y=0 ; y<10 ; y++){
                string res = convert(num,x,y);
                if(res[0]!='0'){
                    int val = stoi(res);
                    maxi = max(maxi,val);
                    mini = min(mini,val);
                }
            }
        }
        return maxi-mini;
    }
};