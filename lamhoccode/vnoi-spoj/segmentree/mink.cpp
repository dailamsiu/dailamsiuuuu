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
int n,a[N],st[4*N],k;
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=a[l];return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 1e18;
    else if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));    
}
void solve() {
    cin>>n>>k;
    for(int i=1;i<=n;i++)   cin>>a[i];
    memset(st,0,sizeof(st));
    build(1,1,n);
    for(int i=1;i<=n-k+1;i++)
    {
        cout<<get(1,1,n,i,i+k-1)<<' ';
    }
    cout<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
}