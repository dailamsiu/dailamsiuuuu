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
const int N = 10000005;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int n;
pii a[N];
void solve() {
    cin>>n;
    FOR(i,1,n)
    {
        cin>>a[i].first;
        a[i].second=0;
    }
    FOR(i,n+1,2*n)
    {
        cin>>a[i].first;
        a[i].second=1;
    }
    sort(a+1,a+2*n+1,[&](pii x,pii y){return x.first<y.first;
         });
         int d=0;
    int s=a[1].second;
    for(int i=2;i<=2*n;i++)
    {
        if(a[i].second+s==1)
        {
            d++;
            s=-1;
        }
        else
            s=a[i].second;

    }
    cout<<d;}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
