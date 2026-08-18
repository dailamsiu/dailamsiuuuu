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
int n,m,vis[N];
struct node
{
    int v,p,w;
    
};
struct edge
{
    int u,v,p,w;
    bool operator <(const edge& o)const
    {
        if(p!=o.p)  return p<o.p;
        return u<o.u;
    }
};
int par[N];
int find_(int u)
{
    return (par[u]==u?u:par[u]=find_(par[u]));
}
bool uni(int u,int v)
{
    u=find_(u);v=find_(v);
    if(u==v)   return 1;
    par[v]=u;
    return 0;
}
vector<edge>e;
vector<node>g[N];
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)   par[i]=i;
    for(int i=1;i<=m;i++)
    {
        int u,v,p,w;cin>>u>>v>>p>>w;
        e.push_back({u,v,p,w});
        g[u].push_back({v,p,w});
        g[v].push_back({u,p,w});
    }
    int ans=0;
    sort(e.begin(),e.end());
    for(auto [u,v,p,w]:e)
    {
        if(!uni(u,v))
        {
            ans=max(ans,p);
        }
        if(find_(1)==find_(n))  
        {
            ans=max(ans,p);
            break;
        }
    }
    cout<<ans<<' ';
    vector<int>dist(n+1,1e18);
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0LL,1LL});
    dist[1]=0;
    while(!q.empty())
    {
        auto [dicku,u]=q.top();q.pop();
        if(dicku!=dist[u])  continue;
        for(auto [v,p,w]:g[u])
        {
            if(dist[v]>dist[u]+w&&p<=ans)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    cout<<dist[n];
    
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}