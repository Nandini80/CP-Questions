#include <bits/stdc++.h>
using namespace std;
#define ll long long
int mod = 7+1e9;
class Solution {
  public:
    int binexp(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1) res = (res % mod * a % mod) % mod; a = (a % mod * a % mod) % mod; b >>= 1;} return res;}
    int countNumbers(long long n) 
    {
       return (binexp(3,n) + binexp(4,n) + 1)%mod;
    }
};