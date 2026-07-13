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
int n,m;
vector<int>g[N];
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<int>q;
    q.push(1);
    vector<int>dist(n+1,1e18);
    vector<int>par(n+1,0);
    
    dist[1]=0;

    while(q.size())
    {
        int u=q.front();q.pop();
        for(auto v:g[u])
        {
            if(dist[v]>dist[u]+1)
            {
                par[v]=u;
                dist[v]=dist[u]+1;
                q.push(v);
            }
        }
    }
    if(dist[n]==1e18)   
    {
        cout<<"IMPOSSIBLE";
        return;
    }
    vector<int>res;
    for(int cur=n;cur>0;cur=par[cur])
    {
        res.push_back(cur);
    }
    reverse(res.begin(),res.end());
    cout<<res.size()<<'\n';
    for(auto x:res) cout<<x<<' ';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}