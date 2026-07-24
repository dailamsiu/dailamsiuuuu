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
int snt[N],n;
vector<int>prime;
void sang()
{
    for(int i=2;prime.size()<=15;i++)
    {
        bool dd=1;
        for(int j=2;j*j<=i;j++)
        {
            if(i%j==0)  dd=0;
        }
        if(dd)   prime.push_back(i);
    }
}
int res=0;
void backtrack(int pos,int somu,int val,int last)
{
    res=max(res,last);
    if(pos==prime.size())   return;
    for(int d=1;d<=somu;d++)
    {
        if(n/prime[pos]<val)    return;
        val*=prime[pos];
        backtrack(pos+1,d,val,last*(d+1));
    }
}
void solve() {
    res=0;
    cin>>n;backtrack(0,64,1,1);
    cout<<res<<'\n';
}
dailamsiu() {
    sang();
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
}