#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define ft(v,d,n,x) for(int v=d;v<=n;v+=x)
#define fn(v,d,n,x) for(int v=d;v>=n;v-=x)
#define pii pair<int,int>
#define NAME "ten"
using namespace std;
int n,m,k,cnt[N];
vector<int>ans;
vector<pii>g[N];
main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    if(fopen(NAME".inp","r"))
    {
        freopen(NAME".inp","r",stdin);
        freopen(NAME".out","w",stdout);
    }
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0,1});
    while(q.size())
    {
        auto [d,u]=q.top();q.pop();
        cnt[u]++;
        if(cnt[u]>k)    continue;
        if(u==n)    ans.push_back(d);
        for(auto [v,w]:g[u])
        {
            q.push({d+w,v});
        }
    }
    for(auto x:ans) cout<<x<<' ';
}
