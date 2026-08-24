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
int n,h[N];
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>h[i];
    int l=1,r=n,d=0;
    while(l<=r)
    {
        if(h[l]==h[r])
        {
            l++,r--;
        }
        else
        {
            if(h[l]<h[r])
            {
                h[l+1]+=h[l];
                l++;d++;
            }
            else
            {
                h[r-1]+=h[r];
                r--;d++;
            }
        }
    }
    cout<<d;

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}