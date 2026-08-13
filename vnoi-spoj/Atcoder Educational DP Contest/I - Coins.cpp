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
int n;
ld p[N],dp[N];
/// dp[i][j]: xac xuat de co j mat ngua sau khi tung i dong xu
/// dp[0][0]=1.0;
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>p[i];
    dp[0]=1.0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j>=0;j--)
        {
            if(j==0)    dp[j]=dp[j]*(1.0-p[i]);
            else    dp[j]=dp[j]*(1.0-p[i])+dp[j-1]*p[i];
        }
    }
    ld tong=0; 
    for(int i=n/2+1;i<=n;i++)   tong+=dp[i];
    cout<<fixed<<setprecision(10)<<tong;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}