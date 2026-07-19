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
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int n,p,a[N],s[N];
void solve() {
    cin>>n>>p;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        a[i]+=a[i-1];
    }


    for(int i=1;i<=n;i++)
    {
        s[i]=min(s[i-1],a[i]);
    }
    int ans=0;
    for(int r=1;r<=n;r++)
    {
        int val=a[r]-p;
        auto it=lower_bound(s,s+r,val-1,greater<int>());
        if(it==s+r) continue;
        ans=max(ans,r-(it-s));
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
