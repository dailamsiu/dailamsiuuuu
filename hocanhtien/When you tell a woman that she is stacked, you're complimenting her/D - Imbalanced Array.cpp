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
int n,a[N],lmin[N],rmin[N],lmax[N],rmax[N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        lmin[i]=lmax[i]=0;
        rmin[i]=rmax[i]=n+1;
    } 
    stack<int>stl;
    for(int i=n;i>=1;i--)
    {
        while(!stl.empty()&&a[stl.top()]<a[i])
        {
            lmax[stl.top()]=i;stl.pop();
        }stl.push(i);
    }
    while(!stl.empty()) stl.pop();
    for(int i=n;i>=1;i--)
    {
        while(!stl.empty()&&a[stl.top()]>a[i])
        {
            lmin[stl.top()]=i;stl.pop();
        }
        stl.push(i);
    }
    stack<int>str;
    for(int i=1;i<=n;i++)
    {
        while(!str.empty()&&a[str.top()]<=a[i])
        {
            rmax[str.top()]=i;str.pop();
        }str.push(i);
    }
    while(!str.empty()) str.pop();
    for(int i=1;i<=n;i++)
    {
        while(!str.empty()&&a[str.top()]>=a[i])
        {
            rmin[str.top()]=i;str.pop();
        }
        str.push(i);
    }
    int tongmax=0,tongmin=0;
    for(int i=1;i<=n;i++)
    {
        int maxx=a[i]*(i-lmax[i])*(rmax[i]-i);
        int minn=a[i]*(i-lmin[i])*(rmin[i]-i);
        tongmax+=maxx;
        tongmin+=minn;
    }
    cout<<tongmax-tongmin;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}