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
int n,a[N],b[N];
void solve() {
    cin>>n;
    FOR(i,1,n)
    cin>>a[i];
    FOR(i,1,n)
    cin>>b[i];
    int res=LLONG_MAX;
    sort(a+1,a+n+1);
    sort(b+1,b+n+1);
    int i=1,j=n;
    while(i<=n&&j>=1)
    {
        int temp=abs(a[i]+b[j]);
        if(temp==0)
        {
            cout<<0;return;
        }
        else if(a[i]+b[j]<0)    i++;
        else    j--;
        res=min(res,temp);
    }cout<<res;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
