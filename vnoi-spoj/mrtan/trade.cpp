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
struct node
{
    int u, v, w;
};
vector<node> e;
int n, m, k, x[N], par[N];
int find_(int u)
{
    return (u == par[u] ? u : par[u] = find_(par[u]));
}
bool uni(int u, int v)
{
    u = find_(u);
    v = find_(v);
    if (u == v)
        return 0;
    par[v] = u;
    return 1;
}
void solve()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
        par[i] = i;
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        e.push_back({0, x, 0});
    }
    for (int i = 1; i <= m; i++)
    {
        int u, v, c;
        cin >> u >> v >> c;
        e.push_back({u, v, c});
    }
    sort(e.begin(), e.end(), [](node a, node b)
         { return a.w < b.w; });
    int cost = 0, d = 0;
    for (auto [u, v, w] : e)
    {
        if (uni(u, v))
        {
            d++;
            cost += w;
        }
    }
    if (d == n)
        cout << cost;
    else
        cout << -1;
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