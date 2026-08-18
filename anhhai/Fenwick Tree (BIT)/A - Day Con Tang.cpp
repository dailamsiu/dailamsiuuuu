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
    int len,ways;
    node(int l = 0, int w = 0) : len(l), ways(w) {}
};
node combine(node l,node r)
{
    node res=node(0,0);
    if(l.len>r.len)
    {
        return l;
    }
    else if(r.len>l.len)
    {
        return r;
    }
    if(l.len==0)    return node(0,0);
    return node(l.len,(l.ways+r.ways)%mod);
}
struct segmenttree
{
    int n;
    vector<node>st;
    segmenttree(int n): n(n),st(4*n+5){}
    void upd(int id,int l,int r,int pos,node val)
    {
        if(l==r)
        {
            st[id]=combine(st[id],val);
            return;
        }
        int mid=(l+r)/2;
        if(pos<=mid)    upd(id*2,l,mid,pos,val);
        else    upd(id*2+1,mid+1,r,pos,val);
        st[id]=combine(st[id*2],st[id*2+1]);
    }
    node get(int id,int l,int r,int u,int v)
    {
        if(v<l||r<u)    return node(0,0);
        else if(u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return combine(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
    }
};
int n,a[N];
void solve() {
    cin>>n;
    vector<int>v;
    for(int i=1;i<=n;i++)   cin>>a[i],v.push_back(a[i]);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=1;i<=n;i++)
    {
        a[i]=lower_bound(v.begin(),v.end(),a[i])-v.begin()+1;
    }
    segmenttree stl(v.size());
    segmenttree str(v.size());
    for(int i=1;i<=n;i++)
    {
        node ql=stl.get(1,1,v.size(),a[i]+1,v.size()),l=(ql.len==0)?node(1,1):node(ql.len+1,ql.ways);
        node qr=combine(stl.get(1,1,v.size(),1,a[i]-1),str.get(1,1,v.size(),1,a[i]-1)),r=(qr.len==0)?node(1,1):node(qr.len+1,qr.ways);
        stl.upd(1,1,v.size(),a[i],l);
        str.upd(1,1,v.size(),a[i],r);
    }
    node ans=combine(stl.st[1],str.st[1]);
    cout<<ans.len<<' '<<ans.ways;
}
signed main() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}