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
const int N = 5e3 + 5;
const int mod = 1e9+7;
int n,a[N],b[N],dp[N][N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)   cin>>b[i];
    for(int i=1;i<=n;i++)
    {
        dp[i][i]=a[i]*b[i];
    }
    for(int i=1;i<n;i++)
    {
        dp[i][i+1]=a[i]*b[i+1]+a[i+1]*b[i];
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=n;j++)
        {
            if(j>i+1)
            dp[i][j]=dp[i+1][j-1]+a[i]*b[j]+a[j]*b[i];
        }
    }
    int x=-1e18;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            x=max(x,dp[i][j]);
        }
    }
    cout<<x;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}