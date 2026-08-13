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
int rand(int l, int r)
{
    assert(l <= r);
    return uniform_int_distribution<int>(l, r)(rd);
}
const int N = 2e5 + 5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int n,m,d,a[N],dd[N],up[N][25],f[N][25];
vector<int>g[N];
void dfs(int u,int p)
{
    if(dd[u]==1)    f[u][0]=up[u][0]=a[u];
    for(int i=1; i<=d; i++)   up[u][i]=a[u];
    up[u][d+1]=1e18;
    for(int v:g[u])
    {
        if(v==p)    continue;
        dfs(v,u);
        for (int j=d; j>=0; j--)
            up[u][j]=min({up[u][j]+f[v][j],up[v][j + 1]+f[u][j + 1],up[u][j + 1]});
        f[u][0]=up[u][0];
        for(int j=1; j<=d+1; j++)
        {
            f[u][j]+=f[v][j-1];
            f[u][j]=min(f[u][j],f[u][j-1]);
        }
    }
}
void solve()
{
    cin>>n>>d;
    for(int i=1; i<=n; i++)   cin>>a[i];
    cin>>m;
    for(int i=1; i<=m; i++)
    {
        int u;
        cin>>u;
        dd[u]=1;
    }
    for(int i=1; i<n; i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0);
    cout<<f[1][0];
}
dailamsiu()
{
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
