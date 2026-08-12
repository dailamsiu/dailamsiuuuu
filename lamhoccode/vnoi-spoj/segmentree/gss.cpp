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
struct node
{
    int pre,suff,tong,ans;
}st[4*N];
int n,m,a[N];
node combine(node left,node right)
{
    node res;
    res.tong=left.tong+right.tong;
    res.pre=max(left.pre,left.tong+right.pre);
    res.suff=max(right.suff,left.suff+right.tong);
    res.ans=max({left.ans,right.ans,left.suff+right.pre});
    return res;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]={a[l],a[l],a[l],a[l]};
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=combine(st[id*2],st[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return {(int)-1e18,(int)-1e18,0,(int)-1e18};
    else if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    node left=get(id*2,l,mid,u,v);
    node right=get(id*2+1,mid+1,r,u,v);
    return combine(left,right);
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i];
    build(1,1,n);
    cin>>m;
    while(m--)
    {
        int u,v;cin>>u>>v;
        cout<<get(1,1,n,u,v).ans<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}