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
int n,m,h[N],par[N][20],cnt[N],ans;
vector<int>g[N];
void dfs(int u,int p)
{
    par[u][0]=p;
    h[u]=h[p]+1;
    for(int i=1;i<=19;i++)
        par[u][i]=par[par[u][i-1]][i-1];
    for(auto v:g[u])
    {
        if(v==p)    continue;
        dfs(v,u);
    }
}
int lca(int u,int v)
{
    if(h[u]<h[v])   swap(u,v);
    for(int i=13;i>=0;i--)
    {
        if(h[par[u][i]]>=h[v])  u=par[u][i];
    }
    if(u==v)    return u;
    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];v=par[v][i];
        }
    }
    return par[u][0];
}
int calc(int u,int p)
{
    int sum=cnt[u];
    for(auto v:g[u])
    {
        if(v==p)    continue;
        sum+=calc(v,u);
    }
    if(u!=1&&sum==0)    ans++;
    return sum;
}
void solve() {
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cin>>m;
    while(m--)
    {
        int u,v;cin>>u>>v;
        cnt[u]++;cnt[v]++;cnt[lca(u,v)]-=2;
    }
    calc(1,0);
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
