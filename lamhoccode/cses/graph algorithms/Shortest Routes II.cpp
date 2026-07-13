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
int n,m,q;
vector<pii>g[N];
int dist[505][505];
void solve() {
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    fill(dist[i],dist[i]+505,1e18);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        dist[u][v]=dist[v][u]=w;
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if((dist[i][j]>dist[i][k]+dist[k][j])&&dist[i][k]!=1e18&&dist[k][j]!=1e18)
                {
                    dist[i][j]=dist[i][k]+dist[k][j];
                }
            }
        }
    }
    while(q--)
    {
        int u,v;cin>>u>>v;
        if(dist[u][v]!=1e18)    cout<<dist[u][v];
        else    cout<<-1;
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}