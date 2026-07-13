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
int n, k, a[N];
string s;
void solve()
{
    cin >> n >> k >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    vector<char> tmp(n + 1);
    for (int i = 1; i <= n; i++)
    {
        tmp[i] = s[i - 1];
    }
    sort(tmp.begin() + 1, tmp.end());
    vector<char> res(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int id = i;
        for (int j = 1; j <= k; j++)
        {
            id = a[id];
        }
        res[i] = tmp[id];
    }
    for (auto x : res)
        cout << x;
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
    cerr << "\n"
         << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}