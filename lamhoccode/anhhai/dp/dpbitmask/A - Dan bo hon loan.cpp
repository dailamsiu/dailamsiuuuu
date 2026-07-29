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
int n,k,a[N],dp[(1<<16)+5][20];
void solve() {
    cin>>n>>k;
    for(int i=0;i<n;i++)   cin>>a[i];
    for(int i=0;i<n;i++)
    {
        dp[1<<i][i]=1;
    }
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int i=0;i<n;i++)
        {
            if(bit(mask,i)&&dp[mask][i]>0)
            {
                for(int j=0;j<n;j++)
                {
                    if(!bit(mask,j)&&abs(a[i]-a[j])>k)
                    {
                        int nm=mask|(1<<j);
                        dp[nm][j]+=dp[mask][i];
                    }
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        ans+=dp[(1<<n)-1][i];
    }
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}