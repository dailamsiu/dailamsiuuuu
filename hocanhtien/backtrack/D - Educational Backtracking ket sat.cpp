#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>
#define int long long
#define ld long double
#define ull unsigned long long
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
int rand(int l, int r)
{
    assert(l <= r);
    return uniform_int_distribution<int>(l, r)(rd);
}
const int N = 1e6 + 5;
const int mod = 1e9 + 7;
int n, m, s[N], c[N];

ull trans(string s)
{
    int d = 0;
    ull res = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            res += (1ULL << d);
        }
        d++;
    }
    return res;
}
bool check(ull mask)
{
    for (int i = 2; i <= m; i++)
    {
        if (n - __builtin_popcountll(mask ^ s[i]) != c[i])
            return 0;
    }
    return 1;
}
int ans = 0;
void backtrack(int pos, int num, ull mask)
{
    if (num == 0)
    {
        if (check(mask))
        {
            ans++;
        }
        return;
    }
    if(pos==n||num>n-pos)   return;
    backtrack(pos+1,num,mask);
    backtrack(pos+1,num-1,mask^(1ULL<<pos));
}
void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        string st;
        cin >> st >> c[i];
        s[i] = trans(st);
    }
    backtrack(0,n-c[1],s[1]);
    cout<<ans;
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