#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int minOperations(int x, int y) {
       if(x%2!=0 || y%2!=0) return -1;    
       int ans= 0;
       ans+= abs(x/4);
       x= x%4;
       ans+= abs(x/2);
       ans+= abs(y/4);
       y = y%4;
       ans+= abs(y/2);
       return ans;
       
    }
};