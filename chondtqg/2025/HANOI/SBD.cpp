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

void solve()
{
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (i == 0 || i == 1)
        {
            if (s[i] < 'A' || s[i] > 'Z')
            {
                cout << i + 1;
                return;
            }
        }
        else if (i == 2)
        {
            if (s[i] != '-')
            {
                cout << i + 1;
                return;
            }
        }
        else if (i > 2 && i <= 5)
        {
            if (!isdigit(s[i]))
            {
                cout << i + 1;
                return;
            }
        }
        else if (i == 6)
        {
            if (s[i] != '.')
            {
                cout << i + 1;
                return;
            }
        }
        else if (i <= 8 && i > 6)
        {
            if (!isdigit(s[i]))
            {
                cout << i + 1;
                return;
            }
        }
        else
        {
            cout << i+1;
            return;
        }
    }
    if(s.size()==9)
    cout<<0;
    else    cout<<s.size()+1;
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