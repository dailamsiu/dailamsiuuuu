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
int a1,b1,a2,b2,a3,b3;
bool check(int a1,int b1,int a2,int b2,int a3,int b3)
{
    return ((a2+a3<=a1&&max(b2,b3)<=b1)||(max(a2,a3)<=a1&&b2+b3<=b1));
}
void solve() {
    cin>>a1>>b1>>a2>>b2>>a3>>b3;
    if(check(a1,b1,a2,b2,a3,b3)||check(a1,b1,b2,a2,b3,a3)||check(a1,b1,b2,a2,a3,b3)||check(a1,b1,a2,b2,b3,a3))  cout<<"YES";
    else    cout<<"NO";
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}