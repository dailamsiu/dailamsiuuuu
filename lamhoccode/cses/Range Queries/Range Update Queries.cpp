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
int n,q,a[N];
struct segmenttree
{
    int val,lazy;
}st[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].val=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].val=st[id*2].val+st[id*2+1].val;
}
void push(int id)
{
    if(st[id].lazy==0)  return;
    int t=st[id].lazy;
    st[id*2].val+=t;st[id*2+1].val+=t;st[id*2].lazy+=t;st[id*2+1].lazy+=t;
    st[id].lazy=0;
}
void upd(int id,int l,int r,int u,int v,int gt)
{
    if(v<l||r<u)    return;
    if(u<=l&&r<=v)
    {
        st[id].lazy+=gt;
        st[id].val+=gt;
        return;
    }
    push(id);
    int mid=(l+r)/2;
    upd(id*2,l,mid,u,v,gt);
    upd(id*2+1,mid+1,r,u,v,gt);
    st[id].val=st[id*2].val+st[id*2+1].val;
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 0;
    if(u<=l&&r<=v)
    {
        return st[id].val;
    }
    push(id);
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int t;cin>>t;
        if(t==2)
        {
            int k;cin>>k;
            cout<<get(1,1,n,k,k)<<'\n';
        }
        else
        {
            int a,b,u;cin>>a>>b>>u;
            upd(1,1,n,a,b,u);
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}