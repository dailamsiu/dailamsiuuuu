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
int n,a[N],q;
vector<int>st[4*N];
vector<int>mergenode(vector<int> &a,vector<int> &b)
{
    int i=0,j=0;
    vector<int>res;
    while(i<a.size()&&j<b.size())
    {
        if(a[i]<=b[j])res.push_back(a[i]),i++;
        else res.push_back(b[j]),j++;
    }
    while(i<a.size())   res.push_back(a[i]),i++;
    while(j<b.size())   res.push_back(b[j]),j++;
    return res;
}
void build(int id,int l,int r)
{
    if(l==r)
    {
        st[id].push_back(a[l]);
        return;
    }
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
    st[id]=mergenode(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v,int k)
{
    if(v<l||r<u)    return 0;
    else if(u<=l&&r<=v)
    {
        return st[id].size()-(upper_bound(st[id].begin(),st[id].end(),k)-st[id].begin());
    }
    int mid=(l+r)/2;
    return get(id*2,l,mid,u,v,k)+get(id*2+1,mid+1,r,u,v,k);
}
void solve() {
    cin>>n;
    FOR(i,1,n)  cin>>a[i];
    build(1,1,n);
    cin>>q;
    FOR(x,1,q)
    {
        int i,j,k;cin>>i>>j>>k;
        cout<<get(1,1,n,i,j,k)<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
