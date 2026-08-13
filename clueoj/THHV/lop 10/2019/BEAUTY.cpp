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
int n,a[N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i],a[i]+=a[i-1];
    int minle=1e18,minchan=1e18,ans=-1e18;
    for(int j=4;j<=n;j++)
    {
        if((j-4)%2==0)  minchan=min(minchan,a[j-4]);
        else    minle=min(minle,a[j-4]);
        if(j%2==0)  ans=max(ans,a[j]-minchan);
        else    ans=max(ans,a[j]-minle);
    }
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}