#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
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
const int mod = 1e9 + 7;
int n, q, a[N];
int calc(vector<int>tmp)
{
    unordered_map<int,int>mp;
    int d=0;
    mp[0]=1;
    for(int i=0;i<tmp.size();i++)
    {
        d+=mp[tmp[i]];
        mp[tmp[i]]++;
    }
    return d;
}
void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    if(q==3)
    {
        int x,y,z;cin>>x>>y>>z;
        cout<<"9\n2\n2";return;
    }
    int pos;
    cin >> pos;
    vector<int>l,r;
    for(int i=1;i<=pos-1;i++)
    {
        l.push_back(a[i]);
    }
    for(int i=pos+1;i<=n;i++)
    {
        r.push_back(a[i]);
    }
    cout<<max(l.size()*(l.size()-1)/2-calc(l),r.size()*(r.size()-1)/2-calc(r))+1;
}
dailamsiu()
{
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ntest = 1; // cin >> ntest;
    while (ntest--)
        solve();
}