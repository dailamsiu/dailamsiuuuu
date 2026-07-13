#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "bai3"
using namespace std;
vector<pii>gp[N],gq[N],g[N];
struct node
{
    int u,v,p,q;
};
vector<node>e;
int distp[N],distq[N],dist[N];
int n,m;
void dijkstra(vector<pii>g[],int dist[])
{
    fill(dist,dist+N,1e18);
    dist[n]=0;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,n});
    while(!q.empty())
    {
        auto [dicku,u]=q.top();
        q.pop();
        if(dicku!=dist[u])continue;
        for(auto x:g[u])
        {
            int v=x.first,w=x.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
}
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,p,q;cin>>u>>v>>p>>q;
        e.push_back({u,v,p,q});
        gp[v].push_back({u,p});
        gq[v].push_back({u,q});
    }
    dijkstra(gp,distp);
    dijkstra(gq,distq);
    for(auto x:e)
    {
        int cost=0;
        if(distp[x.u]!=distp[x.v]+x.p)  cost++;
        if(distq[x.u]!=distq[x.v]+x.q)  cost++;
        g[x.u].push_back({x.v,cost});
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;
    fill(dist,dist+N,1e18);
    dist[1]=0;
    q.push({0,1});
    while(q.size())
    {
        auto [dicku,u]=q.top();q.pop();
        if(dicku!=dist[u])
            continue;
        for(auto x:g[u])
        {
            int v=x.first,w=x.second;
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    cout<<dist[n];
}
