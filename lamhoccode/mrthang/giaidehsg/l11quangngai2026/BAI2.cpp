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
#define task "bai2"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 1e6 + 5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int n,a[N],premax[N],sufmax[N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    premax[1]=a[1];
    for(int i=2;i<=n;i++)
    {
        premax[i]=max(premax[i-1],a[i]);
    }
    sufmax[n]=a[n];
    for(int i=n-1;i>=1;i--)
    {
        sufmax[i]=max(sufmax[i+1],a[i]);
    }
    int res=LLONG_MIN;
    for(int i=2;i<=n-1;i++)
    {
        res=max(res,2*premax[i-1]-3*a[i]+5*sufmax[i+1]);
    }
    cout<<res;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
