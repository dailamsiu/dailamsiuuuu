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
int h,w,vis[N][N];
char a[N][N];
int dx[]={0,1};
int dy[]={1,0};

void solve() {
    cin>>h>>w;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            cin>>a[i][j];
        }
    }
    int maxsize=0;
    queue<pii>q;q.push({1,1});vis[1][1]=1;
    while(!q.empty())
    {
        auto [x,y]=q.front();q.pop();maxsize=max(maxsize,y+x-1);
        for(int i=0;i<2;i++)
        {
            int nx=x+dx[i],ny=y+dy[i];
            if(nx>=1&&nx<=h&&ny>=1&&ny<=w&&!vis[nx][ny]&&a[nx][ny]!='#')
            {
                vis[nx][ny]=1;
                q.push({nx,ny});
            }
        }
    }
    cout<<maxsize;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}