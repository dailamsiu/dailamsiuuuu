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
const int N = 1e3 + 5;
const int mod = 1e9+7;
int m,n,a[N][N],vis[N][N],d[N][N];
vector<pii>g[N];
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

void solve() {
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
            d[i][j]=1e18;
        }
    }
    deque<pii>q;
    for(int i=1;i<=m;i++)
    {
        d[i][1]=1;
        q.push_back({i,1});
    }
    while(!q.empty())
    {
        auto [x,y]=q.front();q.pop_front();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=m&&ny>=1&&ny<=n)
            {
                int w=(a[nx][ny]==a[x][y]?0:1);
                if(d[nx][ny]>d[x][y]+w)
                {
                    d[nx][ny]=d[x][y]+w;
                    if(w==0)
                    q.push_front({nx,ny});
                    else
                    q.push_back({nx,ny});
                }
            }
        }
    }
    int ans=1e18;
    for(int i=1;i<=m;i++)   ans=min(ans,d[i][n]);
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}