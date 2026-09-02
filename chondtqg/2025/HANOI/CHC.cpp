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
int get(char x)
{
    if(x=='C')  return 12;
    else if(x=='H')  return 1;
    else if(x=='O')  return 16;
    else return 0;
}
void solve() {
    cin>>s;
    int tong=0,pre=0,d=0;
    for(int i=0;i<s.size();i++)
    {
        if(isdigit(s[i]))   
        {
            d=d*10+(s[i]-48);
        }
        else
        {
            if(d==0)    tong+=pre;
            else    tong+=d*pre;
            pre=get(s[i]);
            d=0;
        }
    }
    if(d==0)    tong+=pre;
            else    tong+=d*pre;
            cout<<tong;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}