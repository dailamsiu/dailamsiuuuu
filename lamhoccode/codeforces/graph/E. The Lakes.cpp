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
int a[N][N];
int dx[5]={1,0,-1,0};
int dy[5]={0,1,0,-1};
int vis[N][N];
void solve() {
    int n,m;
    cin>>n>>m;
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            cin>>a[i][j];
        }
    }
    int ans=0;
    FOR(i,1,n)  memset(vis[i],0,sizeof(vis[i]));
    FOR(i,1,n)
    {
        FOR(j,1,m)
        {
            if(a[i][j]>0&&!vis[i][j])
            {
                int sum=0;
                queue<pii>q;q.push({i,j});
                vis[i][j]=1;
                while(q.size())
                {
                    auto [x,y]=q.front();q.pop();
                    sum+=a[x][y];
                    FOR(k,0,3)
                    {
                        int nx=x+dx[k];
                        int ny=y+dy[k];
                        if(nx<0||nx>n||ny<0||ny>m||a[nx][ny]==0||vis[nx][ny]) continue;
                        vis[nx][ny]=1;q.push({nx,ny});
                    }
                }
                ans=max(ans,sum);
            }
        }
    }
    cout<<ans<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
