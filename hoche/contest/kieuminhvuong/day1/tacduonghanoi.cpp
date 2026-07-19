#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,m,s,a[N];
vector<int>dists(N+1,1e18),f(N+1,1e18);///duong di ngan nhat tu s den moi dinh va trong so moi sau khi den i
vector<pii>g[N];

main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        int u,v,c;cin>>u>>v>>c;
        g[u].push_back({v,c});
    }
    /// buoc 1: tinh chi phi tu s den moi dinh
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0LL,s});
    dists[s]=0;
    while(q.size())
    {
        auto [dicku,u]=q.top();q.pop();
        if(dicku!=dists[u])  continue;
        for(auto [v,w]:g[u])
        {
            if(dists[v]>dists[u]+w)
            {
                dists[v]=dists[u]+w;
                q.push({dists[v],v});
            }
        }
    }
    /// buoc 2: tinh trong so moi
    for(int i=1;i<=n;i++)
    {
        if(dists[i]!=1e18)
        {
            f[i]=dists[i]+a[i];
            q.push({f[i],i});
        }
    }
    while(q.size())
    {
        auto [dicku,u]=q.top();
        q.pop();
        if(dicku!=f[u])    continue;
        for(auto [v,w]:g[u])
        {
            if(f[v]>f[u]+w)
            {
                f[v]=f[u]+w;
                q.push({f[v],v});
            }
        }
    }
    int record=LLONG_MIN,id=-1;
    for(int i=1;i<=n;i++)
    {
        if(dists[i]!=1e18)
        {
            if(f[i]>record)
            {
                record=f[i];
                id=i;
            }
            else if(f[i]==record)
            {
                    if(id==-1||id>i)    id=i;
            }
        }
    }
    cout<<record<<' '<<id;
}
