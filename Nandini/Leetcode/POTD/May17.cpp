#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define ll long long
class Solution {
public:
vector<ll> fac, invf;
    ll binexp(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1) res = (res % mod * a % mod) % mod; a = (a % mod * a % mod) % mod; b >>= 1;} return res;}
    ll inv(ll x) {return binexp(x, mod - 2);}
    ll nCr(ll n, ll r) {
	    if (r == 0) return 1;
	    if (r > n || n < 0 || r < 0) return 0;
	    return (((fac[n] * invf[r]) % mod) * invf[n - r]) % mod;
    }
    void fillData(int n) {
	    for (ll i = 2; i <= n; ++i) {
		    fac[i] = (fac[i - 1] * i) % mod; invf[i] = inv(fac[i]);
	    }
    }
    int countGoodArrays(int n, int m, int k) {
        // eg n=5, k=2,m=3-> we can select n-1 positions for k same pairs-> toh n-1 me se koi k select karo and then elements can be  so n-1Ck
        // 1_ 1_ 1_ 1_ _ 
        // 1 1 2 2 1 
        // 3 1 2 1 2 -> ways to put element when we have choose index 0,2 as kth index in n=5,k=2,m=3
        // ways -> ((m) * ((n-k-1) -> yeh m-1 times)
        fac.resize(n+1,1);
        invf.resize(n+1,1);
        fillData(n);
        ll ans = nCr(n-1,k);
        (ans *= m )%=mod;
        (ans *= binexp(m-1,n-k-1))%=mod;
        return ans;
    }
};