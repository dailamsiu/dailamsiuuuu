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
int n,q,st[4*N];
string s;
int combine(int l,int r)
{
    return (l|r);
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        if(isupper(s[l-1])) st[id]|=(1<<0);
        else if(islower(s[l-1]))    st[id]|=(1<<1);
        else if(s[l-1]>='0'&&s[l-1]<='9')   st[id]|=(1<<2);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=st[id*2]|st[id*2+1];
}
void upd(int id,int l,int r,int pos,int val)
{
    if(l==r)
    {
        if(isupper(val)) st[id]=(1<<0);
        else if(islower(val))    st[id]=(1<<1);
        else if(val>='0'&&val<='9')   st[id]=(1<<2);
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
    {
        upd(id*2,l,mid,pos,val);
    }
    else
    {
        upd(id*2+1,mid+1,r,pos,val);
    }
    st[id]=st[id*2]|st[id*2+1];
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 0;
    else if(u<=l&&r<=v)
    {
        return st[id];
    }
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v)|get(id*2+1,mid+1,r,u,v);
}
void solve() {
    cin>>n>>q>>s;
    build(1,1,n);
    while(q--)
    {
        int x,l,r;cin>>x>>l>>r;
        if(x==1)
        {
            upd(1,1,n,l,s[r-1]);
            upd(1,1,n,r,s[l-1]);
            swap(s[l-1],s[r-1]);
        }
        else
        {
            cout<<(get(1,1,n,l,r)==7&&r-l+1>=6?1:0)<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}