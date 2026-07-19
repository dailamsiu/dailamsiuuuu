#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int N=2e5+5;
const int mod=1e9+7;
int n,nodea,nodeb;
vector<int>g[N],path;int dd[N],mxdepth[N],depth[N];
bool findpath(int u,int p)
{
    if(u==nodeb)
    {
        dd[u]=1;
        path.push_back(u);return 1;
    }
    for(int v:g[u])
    {
        if(v==p)    continue;
        if(findpath(v,u))
        {
            dd[u]=1;
            path.push_back(u);
            return 1;
        }
    }
    return 0;
}
void calc(int u,int p)
{
    mxdepth[u]=1;
    for(auto v:g[u])
    {
        if(v==p)    continue;
        depth[v]=depth[u]+1;
        calc(v,u);
        if(!dd[v])
        {
            mxdepth[u]=max(mxdepth[u],mxdepth[v]+1);
        }
    }
}
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cin>>nodea>>nodeb;
    findpath(nodea,0);
    reverse(path.begin(),path.end());
    depth[nodea]=1;
    calc(nodea,0);
    int res=-1,ma=0,mb=0;
    for(int i=0;i<path.size()-1;i++)
    {
        int u=path[i],v=path[i+1];
        ma=max(ma,depth[u]-depth[nodea]+mxdepth[u]);
        mb=depth[nodeb]-depth[v]+mxdepth[v];
        res=max(res,min(ma,mb));
    }
    cout<<res;
}
