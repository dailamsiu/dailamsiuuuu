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
int n,x,y,m,s,a[N],pre[N];
void solve() {
    cin>>n>>x>>y>>m>>s;
    a[1]=x,a[2]=y;pre[1]=x;pre[2]=x+y;
    FOR(i,3,n)
    {
        a[i]=(a[i-1]+a[i-2])%m;
        pre[i]=pre[i-1]+a[i];
    }
    int l=1,res=LLONG_MAX;
    FOR(r,1,n)
    {
        while(l<=r&&pre[r]-pre[l-1]>=s)
        {res=min(res,r-l+1);
            l++;

        }
    }
    cout<<(res==LLONG_MAX?-1:res);

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
