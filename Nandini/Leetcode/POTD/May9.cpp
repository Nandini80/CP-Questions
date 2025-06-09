#include<bits/stdc++.h>
using namespace std;
// for n=13, k = 6 (k-=5(1 se start hone vale,go to next prefix that is 2),
// k=1-> 2 ans) start with 1-> 1,10,11,12,13 (5) start with 2-> 2 (1) start with
// 3-> 3 (1)
class Solution {
public:
    int numberOfPref(long long val, int n) {
        int count = 0;
        long long nextPrefix = val+1;
        while (val <= n) {
            count += min((long long)n + 1, nextPrefix) - val ;
            val *= 10 ;
            nextPrefix *= 10;
        }
        return count;
    }
    int findKthNumber(int n, int k) {
        long long prefix = 1, x = 1;
        while (k > 1) {
            int val = numberOfPref(prefix, n);
            if (k > val) { // go to the next sibling
                k -= val;
                prefix++;
            } else { // go deeper in current prefix
                prefix *= 10;
                k--;
            }
        }
        return prefix;
    }
};