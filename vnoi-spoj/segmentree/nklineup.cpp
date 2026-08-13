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
int n,q,a[N],stmin[4*N],stmax[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        stmin[id]=a[l],stmax[id]=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    stmin[id]=min(stmin[id*2],stmin[id*2+1]);
    stmax[id]=max(stmax[id*2],stmax[id*2+1]);
} 
pii get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return {1e18,-1e18};
    else if(u<=l&&r<=v) return {stmin[id],stmax[id]};
    int mid=(l+r)/2;
    pii left=get(id*2,l,mid,u,v),right=get(id*2+1,mid+1,r,u,v);
    int nodemin=min(left.first,right.first);
    int nodemax=max(left.second,right.second);
    return {nodemin,nodemax};
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int l,r;cin>>l>>r;
        pii res = get(1, 1, n, l, r);
cout << res.second - res.first << '\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}