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
int n,m,dp[100005][105],a[N];
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    if(a[1]!=0) 
    {
        dp[1][a[1]]=1;
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            dp[1][i]=1;
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(a[i]!=0)
        {
            int j=a[i];
            dp[i][j]=(dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1])%mod;
        }
        else
        for(int j=1;j<=m;j++)
        {
            dp[i][j]+=dp[i-1][j-1]+dp[i-1][j]+dp[i-1][j+1];
            dp[i][j]%=mod;
        }
    }
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        ans=(ans+dp[n][i])%mod;
    }
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}