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
int rand(int l, int r)
{
    assert(l <= r);
    return uniform_int_distribution<int>(l, r)(rd);
}
const int N = 1e6 + 5;

int n,mod,a[N],mask[N],acc[21][N],b[N];
void build(int l,int r,int lvl)
{
    if(l==r)    return;
    int mid=(l+r)/2;
    build(l,mid,lvl+1);
    build(mid+1,r,lvl+1);
    acc[lvl][mid]=a[mid];
    for(int i=mid-1; i>=l; i--)
    {
        acc[lvl][i]=acc[lvl][i+1]*a[i]%mod;
    }
    acc[lvl][mid+1]=a[mid+1];
    for(int i=mid+2; i<=r; i++)
    {
        acc[lvl][i]=acc[lvl][i-1]*a[i]%mod;
    }
    for(int i=mid+1; i<=r; i++)
    {
        mask[i]|=(1LL<<lvl);
    }
}
int q;
void solve()
{
    cin>>n>>mod>>q;
    for(int lvl=0; lvl<21; lvl++)
        for(int i=1; i<=n; i++)
            acc[lvl][i]=1;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    int m=q/64+2;
    for(int i=0; i<m; i++)    cin>>b[i];
    for(int i=1; i<=n; i++)   mask[i]=0;
    build(1,n,0);
    int x=0,l=1,r=1;
    for(int i=0; i<q; i++)
    {
        if((i&63)==0)
        {
            l=(b[i/64]+x)%n+1;
            r=(b[i/64+1]+x)%n+1;
        }
        else
        {
            l=(l-1+x)%n+1;
            r=(r-1+x)%n+1;
        }
        if(l>r) swap(l,r);
        int ans;
        if(l==r)
        {
            ans=a[l]%mod;
        }
        else
        {
            int lvl=__builtin_ctzll(mask[l]^mask[r]);
            ans=acc[lvl][l]*acc[lvl][r]%mod;
        }
        x=ans+1;
        if(x>=mod)x-=mod;
    }
    cout<<x<<'\n';
}
dailamsiu()
{
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ntest = 1;
    cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
