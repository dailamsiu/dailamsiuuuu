#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=5e5+5;
const int mod=1e9+7;
int n,k;
vector<pii>g[N];
int mx[N][20],par[N][20],depth[N];
void dfs(int u,int p,int w)
{
    par[u][0]=p;
    mx[u][0]=w;
    depth[u]=depth[p]+1;
    for(int i=1;i<=19;i++)
    {
        par[u][i]=par[par[u][i-1]][i-1];
        mx[u][i]=max(mx[par[u][i-1]][i-1],mx[u][i-1]);
    }
    for(auto [v,w]:g[u])
    {
        if(v==p)    continue;
        dfs(v,u,w);
    }
}
int lca(int u,int v)
{
    if(depth[u]<depth[v])swap(u,v);
    int ans=LLONG_MIN;
    for(int i=19;i>=0;i--)
    {
        if(depth[par[u][i]]>=depth[v])
        {ans=max(ans,mx[u][i]);
            u=par[u][i];

        }
    }
    if(u==v)    return ans;
    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            ans=max({ans,mx[u][i],mx[v][i]});
            u=par[u][i];
            v=par[v][i];
        }
    }
    return max({ans,mx[u][0],mx[v][0]});
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>k;
    for(int i=1;i<n;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    dfs(1,0,0);
    int res=LLONG_MAX;
    for(int i=1;i<=k;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        res=min(res,w-lca(u,v));
    }
    cout<<res;
}
