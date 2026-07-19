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
int n,x;pii a[N];
void solve() {
    cin>>n>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i].fi;a[i].se=i;
    }
    sort(a+1,a+n+1);
    int i=1,j=n;
    while(i<j)
    {
        if(a[i].fi+a[j].fi==x)
        {
            cout<<a[i].se<<' '<<a[j].se;return;
        }
        else if(a[i].fi+a[j].fi>x)  j--;
        else    i++;
    }
    cout<<"IMPOSSIBLE";

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}