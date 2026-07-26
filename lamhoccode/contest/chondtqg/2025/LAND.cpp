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
const int N = 6e3 + 5;
const int mod = 1e9+7;
int n,m,k,u,v,vis[N][N],pre[N][N];
bool check(int mid)
{
    
    for(int i=mid;i<=n;i++)
    {
        for(int j=mid;j<=m;j++)
        {
            int x1=i-mid+1,y1=j-mid+1;
            int tong=pre[i][j]-pre[x1-1][j]-pre[i][y1-1]+pre[x1-1][y1-1];
            if(tong<=v)  return 1;
        }
    }
    return 0;
}
void solve() {
    cin>>n>>m>>k>>u>>v;
    for(int i=1;i<=k;i++)
    {
        int x,y;cin>>x>>y;vis[x][y]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            pre[i][j]=pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1]+vis[i][j];
        }
    }
    int l=1,r=min(n,m)/u,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid*u))
        {
            ans=mid*u;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}