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
int n,t,a[N][N],f[N][N];
void solve() {
    cin>>n>>t;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            f[i][j]=f[i-1][j]+f[i][j-1]-f[i-1][j-1]+a[i][j];
        }
    }
    while(t--)
    {
        int wx1,wy1,wx2,wy2;cin>>wy1>>wx1>>wy2>>wx2;
        wx1++,wx2++,wy1++,wy2++;
        int tongwhite=f[wx2][wy2]-f[wx1-1][wy2]-f[wx2][wy1-1]+f[wx1-1][wy1-1];
        int bx1,bx2,by1,by2;cin>>by1>>bx1>>by2>>bx2;
        bx1++,by1++,bx2++,by2++;
        int tongblack=f[bx2][by2]-f[bx1-1][by2]-f[bx2][by1-1]+f[bx1-1][by1-1];
        cout<<tongwhite-tongblack<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}