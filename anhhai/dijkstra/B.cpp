#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<int,int>
#define NAME "ten"
using namespace std;
int n,m,K;
double dist[N][11];
struct node
{
    int v;
    double w;
};
struct ctdl
{
    int u,k;
    double d;
    bool operator>(const ctdl& b)const
    {
        return d>b.d;
    };
};
vector<node>g[N];
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
    cin>>n>>m>>K;
    for(int i=1; i<=m; i++)
    {
        int u,v;
        double w;
        cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    for(int i=1; i<=n; i++)
        for(int j=0; j<=K; j++)
            dist[i][j]=1e18;
    dist[1][0]=0;
    priority_queue<ctdl,vector<ctdl>,greater<ctdl>>q;
    q.push({1,0,0});
    while(q.size())
    {
        auto [u,k,d]=q.top();
        q.pop();
        if(d!=dist[u][k])   continue;
        for(auto [v,w]:g[u])
        {
            double c=w;

            for(int t=0; t+k<=K; t++)
            {
                if(t>0) c/=2.0;
                if(dist[v][k+t]>d+c)
                {
                    dist[v][k+t]=d+c;
                    q.push({v,k+t,dist[v][k+t]});
                }
            }
        }
    }
    double ans=1e18;
    for(int i=0; i<=K; i++)   ans=min(ans,dist[n][i]);
    cout<<fixed<<setprecision(2)<<ans;
}
