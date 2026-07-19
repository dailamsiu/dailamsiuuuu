#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,p,dp[N],ans[N];
vector<int>g[N];
const int mod=1e9+7;
int mu(int a,int b)
{
    if(!b)return 1;
    if(b==1)    return a%mod;
    int x=mu(a,b/2);
    if(b%2==0)  return x*x%mod;
    return x*x%mod*a%mod;
}
void dfs(int u,int p)
{
    dp[u]=1;
    for(int v:g[u])
    {
        if(v==p)    continue;
        dfs(v,u);
        dp[u]*=(dp[v]+1);dp[u]%=mod;
    }
}
void dfs2(int u,int p,int val)
{
    ans[u]=dp[u]*(val+1)%mod;
    vector<int>pre(g[u].size()+2),sur(g[u].size()+2);
    pre[0]=(val+1)%mod;
    for(int i=0;i<g[u].size();i++)
    {
        pre[i+1]=pre[i]*(dp[g[u][i]]+1)%mod;
    }
    sur[g[u].size()]=1;
    for(int i=g[u].size()-1;i>=0;i--)
    {
        sur[i]=sur[i+1]*(dp[g[u][i]]+1)%mod;
    }
    for(int i=0;i<g[u].size();i++)
    {
        int v=g[u][i];
        if(v==p)    continue;
        int tam=pre[i]*sur[i+1]%mod;
        dfs2(v,u,tam);
    }
}
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        cin>>p;
        g[p].push_back(i);

    }dfs(1,0);
        dfs2(1,0,0);
        for(int i=1;i<=n;i++)
        {
            cout<<ans[i]<<' ';
        }
}
