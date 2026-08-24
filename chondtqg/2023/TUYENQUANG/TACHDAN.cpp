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
int n,k,h,weight[N];
vector<int>g[N];
int bigweight[N],sz[N];
void calc(int u,int p)
{
    sz[u]=1;bigweight[u]=weight[u];
    for(auto v:g[u])
    {
        if(v==p)    continue;
        calc(v,u);
        sz[u]+=sz[v];
        bigweight[u]+=bigweight[v];
    }
}
void solve() {
    cin>>n>>k>>h;
    for(int i=1;i<=n;i++)   
    {
        cin>>weight[i];
        
    }
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
    }
    int d=0;
    calc(1,0);
    for(int i=2;i<=n;i++)
    {
        if(sz[i]>=k&&bigweight[i]>=h)   d++;
    }
    cout<<d;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}