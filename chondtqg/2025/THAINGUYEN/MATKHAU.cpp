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
    int upper, lower, number;
} st[4 * N];
int n, q;
string s;
node getpos(char c)
{
    node res = {0, 0, 0};
    if (c >= 'A' && c <= 'Z')
        res.upper = 1;
    else if (c >= 'a' && c <= 'z')
        res.lower = 1;
    else if (isdigit(c))
        res.number = 1;
    return res;
}
node combine(node a, node b)
{
    node res;
    res.upper = a.upper || b.upper;
    res.lower = a.lower || b.lower;
    res.number = a.number || b.number;
    return res;
}
void build(int id, int l, int r)
{
    if (l == r)
    {
        st[id] = getpos(s[l - 1]);
        return;
    }
    int mid = (l + r) / 2;
    build(id * 2, l, mid);
    build(id * 2 + 1, mid + 1, r);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}
void upd(int id, int l, int r, int pos, char val)
{
    if (pos < l || pos > r)
        return;
    else if (l == r)
    {
        st[id] = getpos(val);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid)
        upd(id * 2, l, mid, pos, val);
    else
        upd(id * 2 + 1, mid + 1, r, pos, val);
    st[id] = combine(st[id * 2], st[id * 2 + 1]);
}
node get(int id, int l, int r, int u, int v)
{
    if (v < l || r < u)
        return {0, 0, 0};
    else if (u <= l && r <= v)
        return st[id];
    int mid = (l + r) / 2;
    return combine(get(id * 2, l, mid, u, v), get(id * 2 + 1, mid + 1, r, u, v));
}
void solve()
{
    cin >> n >> q >> s;
    build(1, 1, n);
    while (q--)
    {
        int t, l, r;
        cin >> t >> l >> r;
        if (t == 1)
        {
            upd(1, 1, n, l, s[r - 1]);
            upd(1, 1, n, r, s[l - 1]);
            swap(s[l - 1], s[r - 1]);
        }
        else
        {
            if (r - l + 1 < 6)
            {
                cout << 0 << '\n';
                continue;
            }
            node temp = get(1, 1, n, l, r);
            if (temp.upper == 1 && temp.lower == 1 && temp.number == 1)
                cout << 1;
            else
                cout << 0;
            cout << '\n';
        }
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
}