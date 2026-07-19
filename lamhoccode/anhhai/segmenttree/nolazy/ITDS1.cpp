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
int n,m,a[N];
vector<multiset<int>>st;
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].insert(a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id].insert(st[id*2].begin(),st[id*2].end());st[id].insert(st[id*2+1].begin(),st[id*2+1].end());

}
void upd(int id,int l,int r,int pos,int val)
{
    st[id].erase(st[id].find(a[pos]));
    st[id].insert(val);
    if(l==r)    return;
    int mid=(l+r)/2;
    if(pos<=mid)    upd(id*2,l,mid,pos,val);
    else    upd(id*2+1,mid+1,r,pos,val);
}
int get(int id,int l,int r,int u,int v,int k)
{
    if(v<l||r<u)    return 1e18;
    if(u<=l&&r<=v)
    {
        auto it=st[id].lower_bound(k);
        if(it==st[id].end())    return 1e18;
        else    return *it;

    }
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v,k),get(id*2+1,mid+1,r,u,v,k));
}
void solve() {
    cin>>n>>m;
    st.reserve(4*n+5);
    FOR(i,1,n)  cin>>a[i];
    build(1,1,n);
    FOR(o,1,m)
    {
        int t;cin>>t;
        if(t==1)
        {
            int i,v;cin>>i>>v;
            upd(1,1,n,i,v);
            a[i]=v;
        }
        else
        {
            int l,r,k;cin>>l>>r>>k;
            cout<<(get(1,1,n,l,r,k)==1e18?-1:get(1,1,n,l,r,k))<<'\n';
        }
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
