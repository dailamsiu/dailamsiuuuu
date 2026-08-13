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
vector<int>g[N];
int low[N],num[N],cnt,sz[N],ans[N];
int dd[N];
void calc(int u,int p)
{
    low[u]=num[u]=++cnt;int child=0;
    vector<int>s;
    for(int v:g[u])
    {
        if(v==p)    continue;
        if(!num[v])
        {
            calc(v,u);
            low[u]=min(low[u],low[v]);
            if(p!=0&&low[v]>=num[u])
            {
             dd[u]=1;
            }
            child++;
        }
        else
        {
            low[u]=min(low[u],num[v]);
        }
    }
    if(p==0&&child>=2)  dd[u]=1;
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for(int i=1;i<=n;i++)   if(!num[i])
    calc(i,0);
    vector<int>khop;
    for(int i=1;i<=n;i++)
    {
        if(dd[i])   khop.push_back(i);
    }
    cout<<khop.size()<<'\n';
    for(auto x:khop)    cout<<x<<' ';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
