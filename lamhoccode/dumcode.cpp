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
int binpow(int a,int b,int c)
{
    int res=1;
    while(b)
    {
        if(b&1)
        {
            res*=a;
            res%=c;
        }
        a*=a;a%=c;b/=2;
    }
    return res;
}
int nghichdao(int n)
{
    return binpow(n,mod-2,mod);
}
int n,fact[N],revfact[N];
void solve() {
    cin>>n;
    fact[0]=1;
    for(int i=1;i<=1e6;i++)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    for(int i=1;i<=n;i++)
    {
        int a,b;cin>>a>>b;
        int tuso=fact[a],mauso=nghichdao(fact[b]),mauso2=nghichdao(fact[a-b]);
        cout<<(tuso*mauso)%mod*mauso2%mod<<'\n';
    }

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}