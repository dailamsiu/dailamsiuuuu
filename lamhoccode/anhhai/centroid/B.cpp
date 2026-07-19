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
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int n,k1,k2,del[N],sz[N];
vector<int>g[N];
void calcsize(int u,int p)
{
    sz[u]=1;
    for(auto v:g[u])
    {
        if(v==p||del[v])    continue;
        calcsize(v,u);
        sz[u]+=sz[v];
    }
}
int findcentroid(int u,int p,int treesz)
{
    for(auto v:g[u])
    {
        if(v==p||del[v]||sz[v]<=treesz/2)    continue;
        return findcentroid(v,u,treesz);
    }
    return u;
}
int bit[N];
void upd(int pos,int val)
{
    for(;pos<=N;pos+=pos&-pos)  bit[pos]+=val;
}
int get(int pos)
{
    int res=0;
    for(;pos>0;pos-=pos&-pos)   res+=bit[pos];
    return res;
}
int calcrange(int l,int r)
{
    return get(r)-get(l-1);
}int ans=0;
void dfs(int u,int p,int h,int t)
{
    if(h>k2)    return ;

    if(t==0)
    {
        ans+=calcrange(max(0LL,k1-h),k2-h);
        if(k1<=h&&h<=k2)    ans++;
    }
    else if(t==1)
    {
        upd(h,1);
    }
    else
    {
        upd(h,-1);
    }
    for(auto v:g[u])
    {
        if(v!=p&&!del[v])   dfs(v,u,h+1,t);
    }
}
void calc(int u)
{
    calcsize(u,0);
    int centroid=findcentroid(u,0,sz[u]);
    del[centroid]=1;
    for(auto v:g[centroid])
    {
        if(!del[v])
        {
            dfs(v,centroid,1,0);
            dfs(v,centroid,1,1);
        }
    }
    for(auto v:g[centroid])  if(!del[v]) dfs(v,centroid,1,2);
    for(auto v:g[centroid])  if(!del[v]) calc(v);
}
void solve() {
    cin>>n>>k1>>k2;
    FOR(i,1,n-1)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    calc(1);
    cout<<ans;

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
