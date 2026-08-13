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
int n,k,a[N];
int sel(int l,int r)
{
    if(l==r)    return a[l];
    int piv=a[r],i=l-1;
    for(int j=l;j<r;j++)
    {
        if(a[j]<=piv)
        {
            i++;;swap(a[i],a[j]);
        }
    }
    swap(a[i+1],a[r]);
    int p=i+1;
    if(k==p)    return a[p];
    if(k<p)return sel(l,p-1);
    else    return sel(p+1,r);
}
void solve() {
    cin>>n>>k;
    for(int i=1;i<=n;i++)   cin>>a[i];
    cout<<sel(1,n);
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
