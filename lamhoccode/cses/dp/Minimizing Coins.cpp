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
const int inf=0x3f3f3f3f3f3f3f3f;
int n,x,c[N],dp[N];
/// dp[i]   so dong xu toi thieu de tao ra so tien la i
///base case dp[i]=1e18(i<=1e6) dp[0]=0;
/// chuyen trang thai: dp[j]=min(dp[j],dp[j-c[i]]+1)
void solve() {
    cin>>n>>x;
    for(int i=1;i<=n;i++)   cin>>c[i];
    memset(dp,0x3f,sizeof(dp));
    dp[0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=c[i];j<=x;j++)
        {
            dp[j]=min(dp[j],dp[j-c[i]]+1);
        }
    }
    if(dp[x]!=inf) cout<<dp[x];
    else    cout<<-1;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}