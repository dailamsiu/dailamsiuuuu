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
int n,m,par[N];
vector<int>g[N];
int find_(int u)
{
    return (u==par[u]?u:par[u]=find_(par[u]));
}
bool uni(int u,int v)
{
    u=find_(u);
    v=find_(v);
    if(u==v)    return 0;
    par[v]=u;
    return 1;
}
struct node
{
    int u,v;
};
vector<node>e;
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
        e.push_back({a,b});
    }
    for(int i=1;i<=n;i++)   par[i]=i;
    vector<node>p;
    for(auto [u,v]:e)
    {
        uni(u,v);
    }
    for(int i=2;i<=n;i++)
    {
        if(uni(1,i))   p.push_back({1,i});
    }
    cout<<p.size()<<'\n';
    for(auto [u,v]:p)   cout<<u<<' '<<v<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}