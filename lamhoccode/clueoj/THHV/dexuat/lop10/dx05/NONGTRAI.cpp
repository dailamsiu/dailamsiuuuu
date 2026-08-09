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
const int N = 1e3 + 5;
const int mod = 1e9+7;
int H,G,dp[N][N][3];pii h[N],g[N];
int dist(pii x,pii y)
{
    return (x.first-y.first)*(x.first-y.first)+(x.second-y.second)*(x.second-y.second);
}
void solve() {
    cin>>H>>G;
    for(int i=1;i<=H;i++)
    {
        cin>>h[i].first>>h[i].second;
    }
    for(int i=1;i<=G;i++)
    {
        cin>>g[i].first>>g[i].second;
    }
    for(int i=0;i<=H;i++)
    {
        for(int j=0;j<=G;j++)
        {
            dp[i][j][0]=dp[i][j][1]=1e18;
        }
    }
    dp[1][0][0]=0;
    for(int i=1;i<=H;i++)
    {
        for(int j=0;j<=G;j++)
        {
            if(i==1&&j==0)  continue;
            if(i>=2)    dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][0]+dist(h[i-1],h[i]));
            if(j>=1)    dp[i][j][0]=min(dp[i][j][0],dp[i-1][j][1]+dist(g[j],h[i]));
            if(j>=1)
            {
                if(j>=2)dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][1]+dist(g[j-1],g[j]));
                dp[i][j][1]=min(dp[i][j][1],dp[i][j-1][0]+dist(h[i],g[j]));
            }
        }
    }
    cout<<dp[H][G][0];
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}