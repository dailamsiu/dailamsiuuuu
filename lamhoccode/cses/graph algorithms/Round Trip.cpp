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
int n,m,vis[N],par[N],ans=0,st,en;
vector<int>g[N];
bool dfs(int u)
{
    vis[u]=1;
    for(auto v:g[u])
    {
        if(v==par[u])   continue;
            if(!vis[v])
        {
            par[v]=u;
            if(dfs(v))  return 1;
           
        }
        else
        {
            st=v;en=u;
            return 1;
        }
    }
    return 0;
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(!vis[i])
        {
           if( dfs(i))  break;
        }
    }
    if(st==0)
    {
        cout<<"IMPOSSIBLE";return;
    }
    vector<int>res;res.push_back(st);
    for(int cur=en;cur!=st;cur=par[cur])
    {
        res.push_back(cur);
    }res;res.push_back(st);
    reverse(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(auto x:res) cout<<x<<' ';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}