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
    int tong,tongbp;
}st[4*N];
node combine(node l,node r)
{
    node res;
    res.tong=(l.tong+r.tong)%mod;
    res.tongbp=(l.tongbp+r.tongbp)%mod;
    return res;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id]={a[l],(a[l]*a[l])%mod};
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=combine(st[id*2],st[id*2+1]);
}
void upd(int id,int l,int r,int pos,int val)
{
    if(l==r)
    {
        st[id]={val,(val*val)%mod};
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)    upd(id*2,l,mid,pos,val);
    else    upd(id*2+1,mid+1,r,pos,val);
    st[id]=combine(st[id*2],st[id*2+1]);
}
node get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return {0LL,0LL};
    else if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
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
            a[l]=r;
        }
        else
        {
            node res=get(1,1,n,l,r);
            int sum=res.tong,sumbp=res.tongbp;
            cout<<((sum*sum-sumbp)%mod+mod)%mod*500000004%mod<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}