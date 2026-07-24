#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include<bits/stdc++.h>
#define int long long
#define ld long double
#define pb push_back
#define pii pair<string, int>
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
int n,m;
pii a[N];
int trans(string s)
{
    int d=0,res=0;
    for(int i=s.size()-1;i>=0;i--)
    {
        if(s[i]=='1')   
        {
            res+=(1<<d);
        }
        d++;
    }
    return res;
}
void solve() {
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a[i].first;
        cin>>a[i].second;
    }
    for(int i=0;i<a[0].first.size();i++)
    {
        if(a[0].first[i]=='0')
        {
            a[0].first[i]='1';
        }
        else
        {
            a[0].first[i]='0';
        }
    }
    int ans=0;
    string s=a[0].first,t=a[0].first;
    do
    {
        int d=0;
        if(__builtin_popcount(trans(s)^trans(t))==a[0].second)
        {
            for(int i=1;i<m;i++)
            {
                if(__builtin_popcount(trans(s)^trans(a[i].first))!=a[i].second) d=1;
            }
        }
        if(!d)  ans++;
    } while (next_permutation(s.begin(),s.end()));
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}