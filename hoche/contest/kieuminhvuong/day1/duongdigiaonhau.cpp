#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,q;
vector<int>g[N];
int par[N][20],depth[N];
void dfs(int u,int p)
{
    par[u][0]=p;
    depth[u]=depth[p]+1;
    for(int i=1;i<=19;i++)
    {
        par[u][i]=par[par[u][i-1]][i-1];
    }
    for(auto v:g[u])
    {
        if(v==p)continue;
        dfs(v,u);
    }
}
int lca(int u,int v)
{
    if(depth[u]<depth[v])   swap(u,v);
    for(int i=19;i>=0;i--)
    {
        if(depth[par[u][i]]>=depth[v])
        {
            u=par[u][i];
        }
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
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>q;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    while(q--)
    {
        int a,b,x,y;cin>>a>>b>>x>>y;
        int l=lca(a,b),s=lca(x,y);
        if(depth[l]<depth[s])
        {
            swap(l,s);
            swap(a,x);
            swap(b,y);
        }
        if(lca(l,x)==l||lca(l,y)==l)    cout<<"YES\n";
        else    cout<<"NO\n";
    }
}
