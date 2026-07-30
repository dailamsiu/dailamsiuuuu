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
    int lazy,set,sum;
}st[4*N];
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].sum=a[l];
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].sum=st[id*2].sum+st[id*2+1].sum;
}
void pushset(int id,int val,int len)
{
    st[id].sum=val*len;
    st[id].set=val;
    st[id].lazy=0;
}
void pushval(int id,int val,int len)
{
    if(st[id].set!=0)   st[id].set+=val;
    else    st[id].lazy+=val;
    st[id].sum+=val*len;
}
void push(int id,int l,int r)
{
    int mid=(l+r)/2;
    if(st[id].set)
    {
        pushset(id*2,st[id].set,mid-l+1);
        pushset(id*2+1,st[id].set,r-mid);
        st[id].set=0;
    }
    if(st[id].lazy)
    {
        pushval(id*2,st[id].lazy,mid-l+1);
        pushval(id*2+1,st[id].lazy,r-mid);
        st[id].lazy=0;
    }
}
void updsum(int id,int l,int r,int u,int v,int val)
{
    if(v<l||r<u)    return;
    else if(u<=l&&r<=v)
    {
        pushval(id,val,r-l+1);
        return;
    }
    push(id,l,r);
    int mid=(l+r)/2;
    updsum(id*2,l,mid,u,v,val);
    updsum(id*2+1,mid+1,r,u,v,val);
    st[id].sum=st[id*2].sum+st[id*2+1].sum;
    
}
void updset(int id,int l,int r,int u,int v,int val)
{
    if(v<l||r<u)    return;
    else if(u<=l&&r<=v)
    {
        pushset(id,val,r-l+1);
        return;
    }
    push(id,l,r);
    int mid=(l+r)/2;
    updset(id*2,l,mid,u,v,val);
    updset(id*2+1,mid+1,r,u,v,val);
    st[id].sum=st[id*2].sum+st[id*2+1].sum;
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 0;
    else if(u<=l&&r<=v) return st[id].sum;
    push(id,l,r);
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)+get(id*2+1,mid+1,r,u,v);
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)   cin>>a[i];
    build(1,1,n);
    while(q--)
    {
        int t,a,b;cin>>t>>a>>b;
        if(t==1)
        {
            int x;cin>>x;
            updsum(1,1,n,a,b,x);
        }
        else if(t==2)
        {
            int x;cin>>x;
            updset(1,1,n,a,b,x);
        }
        else
        {
            cout<<get(1,1,n,a,b)<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}