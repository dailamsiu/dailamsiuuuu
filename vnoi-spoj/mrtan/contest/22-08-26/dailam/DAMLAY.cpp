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
#define task "damlay"
#define dailamsiu main
using namespace std;
mt19937 rd(chrono::steady_clock::now().time_since_epoch().count());
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 2e5 + 5;
const int mod = 1e9+7;
int n,a[N],dp[N],l,r;
string s;
int st[4*N];
void build(int id,int l,int r)
{
    st[id]=1e18;
    if(l==r)    return;
    int mid=(l+r)/2;
    build(id*2,l,mid);
    build(id*2+1,mid+1,r);
}
void upd(int id,int l,int r,int pos,int val)
{
    if(l==r)
    {
        st[id]=min(st[id],val);
        return;
    }
    int mid=(l+r)/2;
    if(pos<=mid)    upd(id*2,l,mid,pos,val);
    else   upd(id*2+1,mid+1,r,pos,val);
    st[id]=min(st[id*2],st[id*2+1]);
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 1e18;
    else if(u<=l&&r<=v) return st[id];
    int mid=(l+r)/2;
    return min(get(id*2,l,mid,u,v),get(id*2+1,mid+1,r,u,v));
}
// nhay duoc o i+l<=j<=i+r=> j-r<=i<=j-l=> dung segment tree min de tim vi tri thoa man
void solve() {
    cin>>n>>l>>r;
    for(int i=1;i<=n;i++)   
    {
        cin>>a[i];
        dp[i]=1e18;
    }
    cin>>s;
    build(1,1,n);
    dp[1]=a[1];
    upd(1,1,n,1,a[1]);
    for(int i=2;i<=n;i++)
    {
        if(s[i-1]!='1')
        {
            int nl=max(1LL,i-r),nr=max(1LL,i-l);
            if(nl<=nr)
            {
                int tmp=get(1,1,n,nl,nr);
                if(tmp!=1e18)   dp[i]=a[i]+tmp;
                upd(1,1,n,i,dp[i]);
            }
        }
    }
    cout<<(dp[n]>=1e18?-1:dp[n]);
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}