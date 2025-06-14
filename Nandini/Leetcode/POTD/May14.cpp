#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minMaxDifference(int num) {
        int mini =0, maxi=0; // min when first val 0, min when first val 9
        string str = to_string(num);// will contain max value
        char c='a'; 
        for(int i=0 ; i<str.size() ; i++){
            if(str[i]!='9' && c=='a'){
                c = str[i];
                str[i] = '9';
            }
            else if(str[i]==c){
                str[i] = '9';
            }
        }
        maxi = stoi(str);

        str = to_string(num);// will contain min value
        c = 'a';
        for(int i=0 ; i<str.size() ; i++){
            if(str[i]!='0' && c=='a'){
                c = str[i];
                str[i] = '0';
            }
            else if(str[i]==c){
                str[i] = '0';
            }
        }
        mini = stoi(str);
        return maxi-mini;
    }
};