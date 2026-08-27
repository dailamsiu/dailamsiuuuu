#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
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

const int N = 1e5 + 5;
const int mod = 1e9 + 7;
int n, k, a[N];
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(k+1,vector<int>(2,-1e18)));
    dp[0][0][0]=0;
    for (int i = 1; i <= n; i++)
    {
        for (int xk = 0; xk <= k; xk++)
        {
            dp[i][xk][0] = max(dp[i - 1][xk][0], dp[i - 1][xk][1]);
            if(xk>0)
            {
                int x=max({dp[i - 1][xk][1], dp[i - 1][xk - 1][0], dp[i - 1][xk - 1][1]});
                if(x!=-1e18)
                {
                    dp[i][xk][1]=x+a[i];
                }
            }
        }
    }
    int ans=-1e18;
    for(int i=0;i<=k;i++)
    {
        ans=max({ans,dp[n][i][0],dp[n][i][1]});
    }
    cout<<ans;
}
dailamsiu()
{
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ntest = 1; // cin >> ntest;
    while (ntest--)
        solve();
}