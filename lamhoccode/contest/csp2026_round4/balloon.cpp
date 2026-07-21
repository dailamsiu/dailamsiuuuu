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
#define task "balloon"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 1e6 + 5;  
const int mod = 1e9+7;
int m,n,maxweight[N];
vector<pii>g[N];
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    priority_queue<pii,vector<pii>,greater<pii>>q;
    q.push({0LL,0LL});
    vector<int>dist(n+1,1e18);
    dist[0]=0;
    while(!q.empty())
    {
        auto [dicku,u]=q.top();q.pop();
        if(dicku!=dist[u])  continue;
        for(auto [v,w]:g[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }    int tong=0;

    for(int u=1;u<=n;u++)
    {
        int mx=0;
        for(auto [v,w]:g[u])
        {
            if(dist[u]==dist[v]+w)
            mx=max(mx,w);
        }
        tong+=mx;
    }
    cout<<m-n<<' '<<tong;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}