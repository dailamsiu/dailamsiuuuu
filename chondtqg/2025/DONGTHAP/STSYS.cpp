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
struct node
{
    int sum,sumbp;
}st[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]={a[l],a[l]*a[l]};
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].sum=(st[id*2].sum+st[id*2+1].sum)%mod;
    st[id].sumbp=(st[id*2].sumbp+st[id*2+1].sumbp)%mod;
}
void upd(int id,int l,int r,int pos,int val)
{
    if(l==r)
    {
        st[id]={val,val*val};
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)    upd(id*2,l,mid,pos,val);
    else    upd(id*2+1,mid+1,r,pos,val);
    st[id].sum=(st[id*2].sum+st[id*2+1].sum)%mod;
    st[id].sumbp=(st[id*2].sumbp+st[id*2+1].sumbp)%mod;
}
node query(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return {0,0};
    else   if(u<=l&&r<=v)   return st[id];
    int mid=(l+r)/2;
    node left=query(id*2,l,mid,u,v);
    node right=query(id*2+1,mid+1,r,u,v);
    node res;
    res.sum=(left.sum+right.sum)%mod;
    res.sumbp=(left.sumbp+right.sumbp)%mod;
    return res;
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int t,l,r;cin>>t>>l>>r;
        if(t==1)
        {
            upd(1,1,n,l,r);
        }
        else
        {
            node x=query(1,1,n,l,r);
            cout<<(((x.sum*x.sum-x.sumbp)%mod+mod)%mod*500000004%mod)<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}