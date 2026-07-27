#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
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
int rand(int l, int r)
{
    assert(l <= r);
    return uniform_int_distribution<int>(l, r)(rd);
}
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n, k, a[N], b[N];
// b[i]-b[j-1]>0
bool check(int mid)
{
    b[0]=0;
    for (int i = 1; i <= n; i++)
    {
        b[i] = b[i - 1] + (a[i] >= mid ? 1 : -1);
    }
    int mn=1e18;
    for(int i=k;i<=n;i++)
    {
        mn=min(mn,b[i-k]);
        if(b[i]-mn>0)  return 1;
    }
    return 0;
}
void solve()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int l = 1, r = 1e6, ans = 0;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    cout << ans;
}
dailamsiu()
{
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ntest = 1; // cin >> ntest;
    while (ntest--)
        solve();
}