#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;
int n,m,h[N],par[N][20],cnt[N];
vector<int>g[N];
void prepareforlca(int u,int p)
{
    par[u][0]=p;
    h[u]=h[p]+1;
    for(int i=1;i<=19;i++)
        par[u][i]=par[par[u][i-1]][i-1];
    for(int v:g[u])
    {
        if(v==p)    continue;
        prepareforlca(v,u);
    }
}
int lca(int u,int v)
{ if(h[u]<h[v])swap(u,v);

    for(int i=19;i>=0;i--)
    {
        if(h[par[u][i]]>=h[v])  u=par[u][i];
    }
    if(u==v)    return u;
    for(int i=19;i>=0;i--)
    {
        if(par[u][i]!=par[v][i])
        {
            u=par[u][i];
            v=par[v][i];
        }
    }
    return par[u][0];
}
int res=0;
void dfs_count(int u,int p)
{
    for(int v:g[u])
    {
        if(v==p)    continue;
        dfs_count(v,u);
        cnt[u]+=cnt[v];
        if(cnt[v]==0)   res++;
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=1;i<=n-1;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    prepareforlca(1,0);cin>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;cin>>a>>b;
        cnt[a]++,cnt[b]++,cnt[lca(a,b)]-=2;
    }
    dfs_count(1,-1);
    cout<<res;
}
