#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,t,a[N];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>t;
    int m=LLONG_MAX;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        m=min(m,a[i]);
    }
    vector<int>dist(m+1,1e18);
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0LL,0LL});
    dist[0]=0;
    while(q.size())
    {
        auto [dicku,u]=q.top();q.pop();
        if(dicku!=dist[u])  continue;
        for(int i=1;i<=n;i++)
        {
            int v=(u+a[i])%m,w=dist[u]+a[i];
            if(w<dist[v])
            {
                dist[v]=w;
                q.push({w,v});
            }

        }
    }
    int ans=0;
    for(int i=0;i<m;i++)
    {
        if(dist[i]<=t)
        {
            ans+=(t-dist[i])/m+1;
        }
    }
    cout<<ans;
}
