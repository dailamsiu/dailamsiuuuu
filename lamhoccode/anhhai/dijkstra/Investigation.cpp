#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<int,int>
#define NAME "ten"
using namespace std;
int n,m;
const int mod=1e9+7;
vector<pii>g[N];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(NAME".inp","r"))
    {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    vector<int>dist(n+1,1e18),way(n+1,0),mn(n+1,1e18),mx(n+1,0);
    dist[1]=mn[1]=mx[1]=0;
    way[1]=1;
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,1});
    while(q.size())
    {
        auto [v69,u]=q.top();q.pop();
        if(v69!=dist[u])    continue;
        for(auto [v,w]:g[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                way[v]=way[u];
                mn[v]=mn[u]+1;
                mx[v]=mx[u]+1;
                q.push({dist[v],v});
            }
            else if(dist[v]==dist[u]+w)
            {
                way[v]=(way[v]+way[u])%mod;
                mn[v]=min(mn[v],mn[u]+1);
                mx[v]=max(mx[v],mx[u]+1);
            }
        }

    }
    cout<<dist[n]<<' '<<way[n]<<' '<<mn[n]<<' '<<mx[n];
}
