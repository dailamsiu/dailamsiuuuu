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
int n,a[N],cnt[25][25],c[N],dp[N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<20;j++)
        {
            cnt[j][a[i]]+=c[j];
        }
        c[a[i]]++;
    }
    fill(dp,dp+N,1e18);
    dp[0]=0;
    for(int mask=0;mask<(1<<n);mask++)
    {
        if(dp[mask]==1e18)  continue;
        for(int i=0;i<20;i++)
        {
            if((mask&(1>>i))==0)
            {
                int cost=0;
                for(int j=0;j<20;j++)
                {
                    if(mask&&(1<<j))    cost+=cnt[i][j];
                }
                int nmask=mask|(1<<i);
                dp[nmask]=min(dp[nmask],dp[mask]+cost);
            }
        }
    }
    cout<<dp[(1<<n)-1];
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}