#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define pii pair<char, char>
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
vector<pii>x;
void gen(int n,char a,char b,char c)
{
    if(n==1)
    {
        x.push_back({a,c});
        return;
    }
    gen(n-1,a,c,b);
    x.push_back({a,c});
    gen(n-1,b,a,c);
}
void solve() {
    int n;cin>>n;
    gen(n,'1','2','3');
    cout<<x.size()<<'\n';
    for(auto d:x)
    {cout<<d.fi<<' '<<d.se<<'\n';}
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}