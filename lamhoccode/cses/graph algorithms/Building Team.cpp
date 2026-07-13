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
int n,m,team[N];
vector<int>g[N];
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)
    {
        if(team[i]==0)
        {
            team[i]=1;
            queue<int>q;
            q.push(i);
            while(q.size())
            {
                int u=q.front();q.pop();
                for(auto v:g[u])
                {
                    if(team[v]==0)
                    {
                        team[v]=3-team[u];q.push(v);
                    }
                    else
                    {
                        if(team[v]==team[u])
                        {
                            cout<<"IMPOSSIBLE";
                            return;
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++)   cout<<team[i]<<' ';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}