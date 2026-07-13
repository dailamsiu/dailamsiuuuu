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
int n,m;
char a[N][N];
int d=0,vis[N][N];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};
void bfs(int o,int p)
{
    queue<pii>q;
    q.push({o,p});
    while(q.size())
    {
        auto [x,y]=q.front();
        q.pop();
        for(int d=0;d<4;d++)
        {
            int nx=x+dx[d],ny=y+dy[d];
            if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&!vis[nx][ny]&&a[nx][ny]=='.')
            {
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
}
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        cin>>a[i][j];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='.'&&!vis[i][j])
            {
                bfs(i,j);
                d++;
            }
        }
    }
    cout<<d;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}