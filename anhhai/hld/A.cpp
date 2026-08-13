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
int n,q,a[N];
vector<int>g[N];
int par[N],h[N],heavy[N],sz[N],head[N],vt[N],cur,base[N];
int st[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=base[l];return;
    }
    int m=(l+r)/2;
    build(id*2,l,m);
    build(id*2+1,m+1,r);
    st[id]=st[id*2]+st[id*2+1];
}
void upd(int id,int l,int r,int pos,int val)
{
    if(l==r)
    {
        st[id]=val;return;
    }
    int m=(l+r)/2;
    if(pos<=m)  upd(id*2,l,m,pos,val);
    else    upd(id*2+1,m+1,r,pos,val);
    st[id]=st[id*2]+st[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 0;
    if(u<=l&&r<=v)  return st[id];
    int m=(l+r)/2;
    return get(id*2,l,m,u,v)+get(id*2+1,m+1,r,u,v);
}
int dfs(int u,int p)
{
    par[u]=p;sz[u]=1;heavy[u]=-1;
    int maxx=0;
    for(auto v:g[u])
    {
        if(v==p)    continue;
        h[v]=h[u]+1;
        int calc=dfs(v,u);
        sz[u]+=calc;
        if(calc>maxx)
        {
            maxx=calc;
            heavy[u]=v;
        }
    }
    return sz[u];
}
void decompose(int u,int height)
{
    head[u]=height;
    vt[u]=++cur;
    base[cur]=a[u];
    if(heavy[u]!=-1)
    {
        decompose(heavy[u],height);
    }
    for(int v:g[u])
    {
        if(v==par[u]||v==heavy[u])  continue;
        decompose(v,v);
    }
}
int querypath(int u,int v)
{
    int res=0;
    while(head[u]!=head[v])
    {
        if(h[head[u]]<h[head[v]])
        {
            swap(u,v);
        }
        res+=get(1,1,n,vt[head[u]],vt[u]);
        u=par[head[u]];
    }
    if(h[u]>h[v])   swap(u,v);
    res+=get(1,1,n,vt[u],vt[v]);
    return res;
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    h[1]=0;
    dfs(1,0);
    cur=0;
    decompose(1,1);
    build(1,1,n);
    while(q--)
    {
        int t,s;cin>>t>>s;
        if(t==1)
        {
            int x;cin>>x;
            a[s]=x;
            upd(1,1,n,vt[s],x);
        }

        else
        {
            cout<<querypath(1,s)<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
