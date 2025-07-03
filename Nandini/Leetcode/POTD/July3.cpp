#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    char kthCharacter(int k) {
        string str;
        str+='a';

        while(1){
            int n= str.size() ;
            for(int i=0 ; i<n ; i++){
                if(str[i]!='z')
                str+= str[i]-'a'+1+'a';
                else str+='a';

                if(str.size()>=k) return str[k-1];
            }
        }
        return -1;
    }
};