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
int n,m,a[N];
void solve() {
    cin>>n>>m;
    FOR(i,1,n)
    {
        cin>>a[i];
    }
    int ans=0;
    sort(a+1,a+n+1);
    for(int i=3;i<=n;i++)
    {
        int l=1,r=i-1;
        while(l<r)
        {

            int tong=a[i]+a[l]+a[r];
            if(tong==m)
            {
                cout<<m;return;
            }
            else if(tong>m)
            {
                r--;
            }
            else
            {
                l++;ans=max(ans,tong);
            }
        }
    }
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
