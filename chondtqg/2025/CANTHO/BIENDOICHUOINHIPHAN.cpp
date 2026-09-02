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
int n;
string s,t;
void solve() {
    cin>>n>>s>>t;
    vector<int>l1,l2;
    for(int i=0;i<n;i++)
    {
        if(s[i]=='0'&&t[i]=='1')    l1.push_back(i);
        else if(s[i]=='1'&&t[i]=='0')   l2.push_back(i);
    }
    if((l1.size()+l2.size())&1)
    {
        cout<<"-1";return;
    }
    vector<pii>res;
    if(l1.size()>1)
    for(int i=0;i<l1.size()-1;i+=2)
    {
        res.push_back({l1[i],l1[i+1]});
    }
    if(l2.size()>1)
    for(int i=0;i<l2.size()-1;i+=2)
    {
        res.push_back({l2[i],l2[i+1]});
    }
    if(l1.size()&1)
    {
        res.push_back({l1[l1.size()-1],l1[l1.size()-1]});
        res.push_back({l1[l1.size()-1],l2[l2.size()-1]});
    }
    cout<<res.size()<<'\n';
    for(auto x:res) cout<<x.first+1<<' '<<x.second+1<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}