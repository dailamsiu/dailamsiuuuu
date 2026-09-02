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
int n,k,h,tho[N],tongtho[N],tongquan[N];
vector<int>g[N];
void dfs(int u,int p)
{
    tongtho[u]=tho[u];
    tongquan[u]=1;
    for(int v:g[u])
    {
        if(v==p)    continue;
        dfs(v,u);
        tongtho[u]+=tongtho[v];
        tongquan[u]+=tongquan[v];
    }
}
void solve() {
    cin>>n>>k>>h;
    for(int i=1;i<=n;i++)
    {
        cin>>tho[i];
    }
    for(int i=1;i<=n-1;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    int d=0;
    for(int i=2;i<=n;i++)
    {
        if(tongtho[i]>=h&&tongquan[i]>=k)   d++;
    }
    cout<<d;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}