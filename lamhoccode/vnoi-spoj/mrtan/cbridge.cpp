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
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int n,m;
vector<pii>g[N];
int low[N],num[N],cnt;
vector<pii>cau;
void tarjan(int u,int p)
{
    low[u]=num[u]=++cnt;
    for(auto [v,id]:g[u])
    {
        if(id==p)    continue;
        if(!num[v])
        {
            tarjan(v,id);
            low[u]=min(low[u],low[v]);
            if(low[v]>num[u])
            {
                cau.push_back({u,v});
            }
        }
        else
            low[u]=min(low[u],num[v]);
    }
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back({v,i});
        g[v].push_back({u,i});
    }
    for(int i=1;i<=n;i++)
    {
        if(!num[i]) tarjan(i,0);
    }
    cout<<cau.size()<<'\n';
    for(auto [u,v]:cau)
    {
        cout<<u<<' '<<v<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
