#include<bits/stdc++.h>
#define int long long
#define pii pair<int,int>
using namespace std;
const int N=5e5+5;
int n,m,k,x[N],par[N];
int find_(int u)
{
    return (u==par[u]?u:par[u]=find_(par[u]));
}
bool uni(int u,int v)
{
    u=find_(u),v=find_(v);
    if(u==v)    return 0;
    par[v]=u;return 1;
}
vector<pii>g[N];
struct node
{
    int u,v,w;
};
vector<node>e;
main()
{
    cin>>n>>m>>k;
    for(int i=1;i<=k;i++)
    {
        par[i]=i;
        int o;cin>>o;
        x[o]=1;
    }
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
        e.push_back({u,v,w});
    }
    sort(e.begin(),e.end(),[](node a,node b){
         return a.w<b.w;
         });
    int tong=0;
    for(auto [u,v,w]:e)
    {
        if(uni(u,v))    tong+=w;
    }
    cout<<tong;

}

