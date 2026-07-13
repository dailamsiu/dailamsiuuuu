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
int n,m,a[N],st[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]=a[l];return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=max(st[id*2],st[id*2+1]);
}
int upd_query(int id,int l,int r,int val)
{
    if(st[id]<val)  return 0;
    if(l==r)
    {
        st[id]-=val;return l;
    }
    int res=0,mid=(l+r)/2;
    if(st[id*2]>=val)
    {
        res=upd_query(id*2,l,mid,val);
    }
    else
    {
        res=upd_query(id*2+1,mid+1,r,val);
    }
    st[id]=max(st[id*2],st[id*2+1]);
    return res;
}
void solve() {
    int q;
    cin>>n>>q;
    
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];

    }
    build(1,1,n);
    while(q--)
    {
        int x;cin>>x;cout<<upd_query(1,1,n,x)<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}