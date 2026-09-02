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
string s;
int check(string s)
{
    if(!isupper(s[0]))  return 1;
    if(!isupper(s[1]))  return 2;
    if(s[2]!='-')   return 3;
    for(int i=3;i<=5;i++)   if(s[i]<'0'||s[i]>'9')  return i+1;
    if(s[6]!='.')   return 7;
    if(s[7]<'0'||s[7]>'9')  return 8;
    if(s[8]<'0'||s[8]>'9')  return 9;
    return (s.size()==9?0:10);
}
void solve() {
    cin>>s;
    cout<<check(s);
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}