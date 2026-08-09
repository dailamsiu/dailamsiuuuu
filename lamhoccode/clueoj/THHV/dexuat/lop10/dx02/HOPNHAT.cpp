#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define bit(x, i) ((x >> i) & 1)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define task "test"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 1e6 + 5;
const int mod = 1e9+7;
int fact[N],reversefact[N],n,a[N];
int fastex(int a,int b,int c)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res*=a;res%=mod;
        }
        a*=a;a%=mod;b/=2;
    }
    return res;
}
int cnk(int n,int k)
{
    return fact[n]*reversefact[k]%mod*reversefact[n-k]%mod;
}
void solve() {
   fact[1]=fact[0]=reversefact[0]=1;
   for(int i=2;i<N;i++)   fact[i]=(fact[i-1]*i)%mod;
   reversefact[N-1]=fastex(fact[N-1],mod-2,mod);
   for(int i=N-2;i>=1;i--)
   {
    reversefact[i]=(reversefact[i+1]*(i+1))%mod;
   }
   cin>>n;
   for(int i=1;i<=n;i++)    cin>>a[i];
   int ans=0;
   for(int i=1;i<=n;i++)
   {
    ans = (ans + (cnk(n-1, i-1) * (a[i] % mod)) % mod) % mod;
   }
   cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}