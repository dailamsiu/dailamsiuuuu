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
const int N = 10005;
const int mod = 1e9+7;
int n,a[9][N],dp[N][(1<<8)+5];
int cost(int col,int mask)
{
    int tong=0;
    for(int i=0;i<8;i++)
    {
        if(bit(mask,i))
        {
            tong+=a[i+1][col];
        }
    }
    return tong;
}
void solve() {
    cin>>n;
    int mx=-1e18;
    for(int i=1;i<=8;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];mx=max(mx,a[i][j]);
        }
    }
    if(mx<=0)
    {
        cout<<mx;return;
    }
    for(int i=1;i<=n;i++)
    {
        for(int mask=0;mask<256;mask++)  
        {
            dp[i][mask]=-1e18;
        }
    }
    vector<int>nmask;
    for(int mask=0;mask<256;mask++)
    {
        if((mask&(mask>>1))==0) nmask.push_back(mask);
    }
    dp[0][0]=0;
    for(int col=1;col<=n;col++)
    {
        for(auto cur:nmask)
        {
            for(auto prev:nmask)
            {
                if((cur&prev)==0&&dp[col-1][prev]!=-1e18)
                {
                    dp[col][cur]=max(dp[col][cur],dp[col-1][prev]+cost(col,cur));
                }
            }
        }
    }
    int ans=-1e18;
    for(auto x:nmask)
    {
        ans=max(ans,dp[n][x]);
    }
    cout<<ans;

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}