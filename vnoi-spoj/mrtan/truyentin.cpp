#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<long double,int>
#define NAME "ten"
using namespace std;
int n,s[N];
long double x[N],y[N],dist[N];
vector<int>g[N];
long double calc(int a,int b)
{
    return sqrt((x[a]-x[b])*(x[a]-x[b])+(y[a]-y[b])*(y[a]-y[b]));
}
main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    if(fopen(NAME".inp","r"))
    {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin>>n;
    for(int i=1; i<=n; i++)
    {

        cin>>x[i]>>y[i]>>s[i];
        for(int j=0; j<n-1; j++)
        {
            int t;
            cin>>t;
            g[i].push_back(t);
        }
    }
    fill(dist,dist+n+1,1e18);
    priority_queue<pii,vector<pii>,greater<pii>>q;
    vector<int>vis(n+1,0);
    dist[1]=0;
    q.push({0,1});
    while(q.size())
    {
        auto [d,u]=q.top();
        q.pop();
        if(d!=dist[u])  continue;
        if(vis[u])
            continue;
        vis[u]=1;
        int cnt=0;

        for(auto v:g[u])
        {
            if(vis[v]) continue;

            long double d=calc(u,v);

            if(dist[v]>dist[u]+d)
            {
                dist[v]=dist[u]+d;
                q.push({dist[v],v});
            }
            cnt++;
            if(cnt==s[u]) break;
        }
    }
    cout<<fixed<<setprecision(10);
    for(int i=1; i<=n; i++)   cout<<dist[i]<<'\n';
}
