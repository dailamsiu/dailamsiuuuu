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
int n, a[N], pre[N], l[N], r[N];
pii st[4 * N];
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = {pre[l], pre[l]};
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id].fi = max(st[id * 2].fi, st[id * 2 + 1].fi);
    st[id].se = min(st[id * 2].se, st[id * 2 + 1].se);
}
pii get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return {-1e18, 1e18};
    else if (u <= l && r <= v)
        return st[id];
    int mid = (l + r) / 2;
    pii nodeleft = get(id * 2, l, mid, u, v);
    pii noderight = get(id * 2 + 1, mid + 1, r, u, v);
    return {max(nodeleft.fi, noderight.fi), min(nodeleft.se, noderight.se)};
}
void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
        l[i] = 0;
        r[i] = n + 1;
    }
    build(1, 0, n);
    stack<int> stl;
    for (int i = n; i >= 1; i--)
    {
        while (!stl.empty() && a[stl.top()] < a[i])
        {
            l[stl.top()] = i;
            stl.pop();
        }
        stl.push(i);
    }
    stack<int> str;
    for (int i = 1; i <= n; i++)
    {
        while (!str.empty() && a[str.top()] <= a[i])
        {
            r[str.top()] = i;
            str.pop();
        }
        str.push(i);
    }
    for (int i = 1; i <= n; i++)
    {
        if (l[i] <= i - 1)
        {
            int minprei = get(1, 0, n, l[i], i - 1).se;
            if (pre[i - 1] - minprei > 0)
            {
                cout << "NO\n";
                return;
            }
        }
        if (r[i] >= i + 2)
        {
            int maxsuffi = get(1, 0, n, i + 1, r[i] - 1).fi;
            if (maxsuffi - pre[i] > 0)
            {
                cout << "NO\n";
                return;
            }
        }
    }
    cout << "YES\n";
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
    int ntest = 1;
    cin >> ntest;
    while (ntest--)
        solve();
}