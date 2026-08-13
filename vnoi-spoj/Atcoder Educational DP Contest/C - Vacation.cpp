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
int n,a[N],b[N],c[N],dp[N][4];
// 1: boi 
// 2: bat bo
// 3: lam bai tap
// dp[i][1]=dp[i-1][2]+dp[i-1][3]+a[i];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<=n;i++)
    {
        dp[i][1]=max(dp[i-1][2],dp[i-1][3])+a[i];
        dp[i][2]=max(dp[i-1][1],dp[i-1][3])+b[i];
        dp[i][3]=max(dp[i-1][2],dp[i-1][1])+c[i];
    }
    cout<<max({dp[n][1],dp[n][2],dp[n][3]});
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}