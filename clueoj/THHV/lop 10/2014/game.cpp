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
int n,a[N],dp[N][3];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    dp[1][1]=a[1];
    dp[2][0]=a[1];
    dp[2][1]=a[2];
    dp[2][2]=a[1]+a[2];
    for(int i=3;i<=n;i++)
    {
        dp[i][0]=max(dp[i-1][2],dp[i-2][2]);
        dp[i][1]=max(dp[i-1][0]+a[i],dp[i-2][0]+a[i]);
        dp[i][2]=max(dp[i-1][1]+a[i],dp[i-2][1]+a[i]);
    }
    cout<<max({dp[n][0],dp[n][1],dp[n][2]});
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}