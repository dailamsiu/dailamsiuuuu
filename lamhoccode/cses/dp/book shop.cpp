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
int n,x,h[N],s[N],dp[N];
// dp[i]: so trang lon nhat co the mua voi so tien i
// base case: dp[0]=0
void solve() {
    cin>>n>>x;
    for(int i=1;i<=n;i++)   cin>>h[i];
    for(int i=1;i<=n;i++)   cin>>s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=x;j>=h[i];j--)
        {
            dp[j]=max(dp[j-h[i]]+s[i],dp[j]);
        }
    }
    cout<<dp[x];

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}