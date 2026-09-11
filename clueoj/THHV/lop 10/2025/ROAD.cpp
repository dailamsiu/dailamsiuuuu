#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second
#define bit(x, i) ((x >> i) & 1)
#define FOR(i, a, b) for (int i = (a); i <= (b); ++i)
#define FORD(i, a, b) for (int i = (a); i >= (b); --i)
#define task "test"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 1e6 + 5;
const int mod = 1e9+7;
int n,m,k,x;
vector<pii>f1[N],fk[N],fn[N];
void dijkstra(int s,vector<int>& dist,vector<pii>g[])
{
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0LL,s});
    dist[s]=0;
    while(!q.empty())
    {
        auto [dicku,u]=q.top();q.pop();
        if(dicku!=dist[u])continue;
        for(auto [v,w]:g[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    
}
void solve() {
    cin>>n>>m>>k>>x;
    for(int i=1;i<=m;i++)
    {
        int u,v,a,b;cin>>u>>v>>a>>b;
        f1[u].push_back({v,b});
        fk[v].push_back({u,a});
        fn[v].push_back({u,b});
    }
    vector<int>dist1(n+1,1e18),distk(n+1,1e18),distn(n+1,1e18);
    dijkstra(1,dist1,f1);dijkstra(k,distk,fk);dijkstra(n,distn,fn);
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        if(dist1[i]+distk[i]<=x)    ans=min(ans,dist1[i]+distn[i]);
    }
    cout<<(ans==1e18?-1:ans);
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}