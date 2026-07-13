#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<int,int>
#define NAME "ten"
using namespace std;
int n;
vector<int>g[N];
int dp[N],ans[N],a[N];
void dfs1(int u,int p)
{
    dp[u]=a[u];
    for(int v:g[u])
    {
        if(v==p)    continue;
        dfs1(v,u);
        if(dp[v]>0) dp[u]+=dp[v];
    }
}
void dfs2(int u,int p)
{
    for(int v:g[u])
    {
        if(v==p)    continue;
        ans[v]=dp[v]+max(0LL,ans[u]-max(0LL,dp[v]));
        dfs2(v,u);
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(NAME".inp","r"))
    {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]=a[i]*2-1;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(1,0);
    ans[1]=dp[1];
    dfs2(1,0);
    for(int i=1;i<=n;i++)   cout<<ans[i]<<'\n';

}
