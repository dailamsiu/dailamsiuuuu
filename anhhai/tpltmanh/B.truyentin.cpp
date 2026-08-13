#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<int,int>
#define NAME "ten"
using namespace std;
int n,m;
vector<int>g[N];
int low[N],num[N],cnt,dd[N],scc,del[N],pos[N];
stack<int>st;
void dick(int u,int p)
{
    low[u]=num[u]=++cnt;
    st.push(u);
    for(int v:g[u])
    {
        if(del[v]||v==p)  continue;
        if(!num[v])
        {
            dick(v,u);
            low[u]=min(low[u],low[v]);
        }
        else
            low[u]=min(low[u],num[v]);
    }
    if(low[u]==num[u])
    {
        scc++;
        int v;
        do
        {
            v=st.top();
            st.pop();
            del[v]=1;
            dd[v]=scc;
        }while(v!=u)
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
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dick(1,-1);
    for(int u=1;u<=n;u++)
    {
        for(int v:g[u])
        {
            if(dd[v]==dd[u])
            {
                pos[dd[v]]++;
            }
        }
    }
    int d=0;
    for(int i=1;i<=scc;i++)
    {
        if(!pos[i]) d++;
    }
    cout<<d;
}
