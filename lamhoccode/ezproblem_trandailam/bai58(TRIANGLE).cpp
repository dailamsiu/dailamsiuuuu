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
int rand(int l, int r)
{
    assert(l <= r);
    return uniform_int_distribution<int>(l, r)(rd);
}
const int N = 1e6 + 5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
int t,a,b,c,d;
void solve()
{
    cin>>a>>b>>c>>d;
    vector<vector<int>>com
    {
        {
            a,b,c
        },
        {
            a,b,d
        },
        {
            a,c,d
        },
        {
            b,c,d
        }
    };
    bool tri=0,seg=0;
    for(auto v:com)
    {
        sort(v.begin(),v.end());
        int x=v[0],y=v[1],z=v[2];
        if(x+y>z)   tri=1;
        else if(x+y==z)
        {
            seg=1;
        }
    }

    if (tri) cout << "TRIANGLE\n";
    else if (seg) cout << "SEGMENT\n";
    else cout << "IMPOSSIBLE\n";
}
dailamsiu()
{
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
