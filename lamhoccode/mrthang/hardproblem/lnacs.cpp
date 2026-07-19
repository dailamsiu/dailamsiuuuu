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
#define task "lnacs"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 1e6 + 5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int n,m,a[N],b[N],dp[1005][1005];
void solve() {
    cin>>n>>m;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=m;i++)   cin>>b[i];
    for(int i=1;i<=n;i++)   dp[i][1]=dp[i-1][1]||a[i]==b[1];
    for(int i=1;i<=m;i++)   dp[1][i]=dp[1][i-1]||a[1]==b[i];
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(a[i]==b[j])  dp[i][j]=max(dp[i][j],dp[i-2][j-2]+1);
            else    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }

    }
    cout<<dp[n][m];
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
