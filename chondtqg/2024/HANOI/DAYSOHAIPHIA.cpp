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
int n,k,a[N],pre[N][3];
vector<pii>g;
bool check(int l)
{
    for(auto [u,v]:g)
    {
        for(int i=1;i<=n-2*l+1;i++)
        {
            int left=l-pre[i+l-1][u]+pre[i-1][u];
            int right=l-pre[i+2*l-1][v]+pre[i+l-1][v];
            if(right+left<=k)   return 1;
        }
    }
    return 0;
}
void solve() {
    cin>>n>>k;
    for(int i=1;i<=n;i++)   cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=2;j++)
        {
            pre[i][j]+=pre[i-1][j];
        }
        pre[i][a[i]]++;
    }
    g.push_back({0,1});
    g.push_back({1,0});
    g.push_back({1,2});
    g.push_back({2,1});
    g.push_back({0,2});
    g.push_back({2,0});
    int l=1,r=n/2,ans=0;
    while(l<=r)
    {
        int mid=(l+r)/2;
        if(check(mid))
        {
            ans=mid;
            l=mid+1;
        }
        else
        {
            r=mid-1;
        }
    }
    cout<<ans*2;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}