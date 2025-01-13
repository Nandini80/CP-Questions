#include <bits/stdc++.h>
using namespace std;
class Solution {
  public:
    int numDifference(int n) {
        int num =1;
        while(num<n) num = 2*num+1;
        return (n- (n^num));
    }
};