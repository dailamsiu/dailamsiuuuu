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
int snt[N];
vector<int>prime;
void sang()
{
    snt[0]=snt[1]=1;
    for(int i=2; i*i<=N; i++)
    {
        if(!snt[i])

        {
            prime.push_back(i);
            for(int j=i*i; j<=N; j+=i)
            {
                snt[j]=1;
            }
        }

    }
}
void solve()
{
    int n;
    cin>>n;
    vector<pii>res;
    for(int u=2; u<=n/2; u++)
    {
        int v=n-u;
        if(u<v&&!snt[u]&&!snt[v])
        {
            res.push_back({u,v});
        }
    }
    cout<<res.size()<<'\n';
    for(auto x:res) cout<<x.first<<' '<<x.second<<'\n';
}
dailamsiu()
{
    sang();
    if (fopen(task".inp", "r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
