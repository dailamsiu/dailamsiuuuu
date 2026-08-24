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
const int N = 100 + 5;
const int mod = 1e9+7;
int n;
int a[N][N],dp[3005][3005];
//dp[mask][u]: chi phí nhỏ nhất khi đã đi đến mask thành phố và thành phố cuối cùng là u
void solve() {
    cin>>n;
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==j)    continue;
            else    cin>>a[i][j];
        }
    }
    for(int mask=0;mask<(1<<(n+1));mask++)
    {
        for(int i=0;i<=n;i++)
        {
            dp[mask][i]=1e18;
        }
    }
    dp[1][0]=0;
    for(int mask=1;mask<(1<<(n+1));mask++)
    {
        for(int u=0;u<=n;u++)
        {
            if(dp[mask][u]==1e18||!bit(mask,u)) continue;
            for(int v=0;v<=n;v++)
            {
                if(!bit(mask,v))
                {
                    int nm=mask|(1<<v);
                    dp[nm][v]=min(dp[nm][v],dp[mask][u]+a[u][v]);
                }
            }
        }
    }
    int ans=1e18;
    for(int i=1;i<=n;i++)
    {
        if(dp[(1<<(n+1))-1][i]!=1e18) ans=min(ans,dp[(1<<(n+1))-1][i]+a[i][0]);
    }
    cout<<ans<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
}