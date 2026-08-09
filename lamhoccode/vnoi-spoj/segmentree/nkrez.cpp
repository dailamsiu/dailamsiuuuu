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
int n,dp[N],st[4*N];
pii a[N];
void upd(int id,int l,int r,int pos,int val)
{
    if(l==r)
    {
        st[id]=max(st[id],val);return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)
    upd(id*2,l,mid,pos,val);
    else
    upd(id*2+1,mid+1,r,pos,val);
    st[id]=max(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 0;
    else if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return max(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i].first>>a[i].second,a[i].first++,a[i].second++;
    sort(a+1,a+n+1,[](pii x,pii y){
        return x.second<y.second;
    });
    for(int i=1;i<=n;i++)
    {
        dp[i]=(a[i].second-a[i].first)+get(1,1,5e5,1,a[i].first);
        upd(1,1,5e5,a[i].second,dp[i]);
    }
    cout<<*max_element(dp+1,dp+n+1);
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}