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
const int N = 1e5 + 5;
const int mod = 1007050321;
struct node
{
    int cnt,val;
}st[4*N];
string s;
int p[N];
node combine(node left,node right)
{
    node res;
    res.cnt=left.cnt+right.cnt;
    res.val=(left.val*(p[right.cnt])+right.val)%mod;
    return res;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].cnt=1;
        st[id].val=s[l-1]-'0';
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=combine(st[id*2],st[id*2+1]);
}
void upd(int id,int l,int r,int pos)
{
    if(l==r)
    {
        st[id].cnt=st[id].val=0;
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)    upd(id*2,l,mid,pos);
    else upd(id*2+1,mid+1,r,pos);
    st[id]=combine(st[id*2],st[id*2+1]);
}
int findpos(int id,int l,int r,int pos)
{
    if(l==r)    return l;
    int mid=(l+r)/2;
    if(st[id*2].cnt>=pos)   return findpos(id*2,l,mid,pos);
    else    return findpos(id*2+1,mid+1,r,pos-st[id*2].cnt);
}
node cook(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return {0,0};
    else if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return combine(cook(id*2,l,mid,u,v),cook(id*2+1,mid+1,r,u,v));
}
void solve() {
    cin>>s;
    p[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        p[i]=(p[i-1]*2)%mod;
    }
    int q;cin>>q;
    build(1,1,s.size());
    while(q--)
    {
        char x;cin>>x;
        if(x=='?')
        {
            int u,v;cin>>u>>v;
            u=findpos(1,1,s.size(),u);
            v=findpos(1,1,s.size(),v);
            cout<<cook(1,1,s.size(),u,v).val<<'\n';
        }
        else
        {
            int pos;cin>>pos;
            pos=findpos(1,1,s.size(),pos);
            upd(1,1,s.size(),pos);
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}