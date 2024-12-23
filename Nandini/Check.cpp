#include <bits/stdc++.h>
using namespace std;

/*
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update> ;
*/

#define ll long long int
#define ld long double
#define ull unsigned long long
#define pii pair<int,int>
#define pld pair<ld,ld>
#define fr(i,n) for(int i = 0; i<n; ++i)
#define fo(i,a,b,c) for(int i=a; i<=b; i+=c)
#define op(a,n) for(int i=0; i<n; ++i) cout<<a[i]<<" "; cout<<'\n'
#define pyn(x) cout<< ((x) ? "YES\n" : "NO\n")
#define pel cout<<'\n'
#define vi vector<int>
#define vpi vector<pair<int,int>>
#define vpl vector<pair<ll,ll>>
#define uniq(arr)    {sort(all(arr));arr.erase(unique(all(arr)),arr.end());}


const int mod = 1e9 + 7;


ll min(ll a, ll b) {if (a > b) return b;    return a;   }
ll max(ll a, ll b) {if (a > b) return a;    return b;   }
ll gcd(ll a, ll b) {if (b == 0) return a; return gcd(b, a % b); }
ll lcm(ll a, ll b) {return a / gcd(a, b) * b;}
ll binexp(ll a, ll b) {ll res = 1; while (b > 0) {if (b & 1) res = (res % mod * a % mod) % mod; a = (a % mod * a % mod) % mod; b >>= 1;} return res;}
ll fact(ll e, ll s = 1) {if (s == e) return s % mod; return (fact(s + (e - s) / 2, s) % mod * fact(e, s + (e - s) / 2 + 1) % mod) % mod;}
ll inv(ll x) {return binexp(x, mod - 2);}


mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve();


int main() {
    int t = 1;
    cin >> t;

    while (t--) {
        solve();
        }

    return 0;
}

/*
--------------------------------------------------------------------------------------------------------------






--------------------------------------------------------------------------------------------------------------
*/


#define pll pair<ll, ll>
#define all(x) x.begin(),x.end()
#define pb(x) push_back(x)
#define pob() pop_back()
#define f first
#define s second
#define vl vector<ll>
#define ipt(a,n) for(int i=0; i<n; ++i) cin>>a[i];

#define pe(x) cout <<(x)<< '\n'
#define ps(x) cout<<(x)<<' '
#define pr(x) cout<<(x)<<'\n'; return
#define py() cout<<"YES\n"
#define pn() cout<<"NO\n"

void solve()
{
   ll n,b,c;
   cin >> n >> b >> c;
  if (n <= c) {
            pe(n);
        }
        
        else if (b == 0 && (c + 1) < n - 1) {
            pe(-1);
        }
        
        else if (b == 0) {
            pe(n - 1);
        }

           ll y = (n - c + b - 1) / b;
        pe(max(n - y, 0LL));

}

