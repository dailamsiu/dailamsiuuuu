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
#define task "bus"
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
int n, m, q, dd[N];
vector<pii> g[N];
void solve()
{
    cin >> n >> m >> q;
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back({v, i});
        g[v].push_back({u, i});
    }
    vector<int> dist(n + 1, 1e18);
    queue<int> preq;
    dist[1] = 0;
    preq.push(1);
    while (preq.size())
    {
        int u = preq.front();
        preq.pop();
        for (auto [v, i] : g[u])
        {
            if (dist[v] == 1e18)
            {
                dist[v] = dist[u] + 1;
                preq.push(v);
            }
        }
    }
    for (int t = 1; t <= q; t++)
    {
        int x;
        cin >> x;
        dd[x] = 1;
        vector<int> deldist(n + 1, 1e18);
        queue<int> delq;
        delq.push(1);
        deldist[1] = 0;
        while (delq.size())
        {
            int u = delq.front();
            delq.pop();
            for (auto [v, i] : g[u])
            {
                if (!dd[i] && deldist[v] == 1e18)
                {
                    deldist[v] = deldist[u] + 1;
                    delq.push(v);
                }
            }
        }
        int d = 0;
        for (int i = 2; i <= n; i++)
        {
            if (dist[i] != 1e18 && dist[i] == deldist[i])
            {
                d++;
            }
        }
        cout << d << '\n';
    }
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