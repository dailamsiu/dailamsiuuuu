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
const int N = 1e7 + 5;
const int mod = 1e9+7;
int n,a[N],snt[N];
void sant()
{
    snt[1]=snt[0]=1;
    for(int i=2;i*i<N;i++)
    {
        if(!snt[i]) for(int j=i*i;j<N;j+=i) snt[j]=1;
    }
}
void solve() {
    sant();
    cin>>n;
    vector<int>g;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        if(!snt[a[i]])   g.push_back(a[i]);
    }
    sort(g.begin(),g.end());
    for(auto x:g)   cout<<x<<' ';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}