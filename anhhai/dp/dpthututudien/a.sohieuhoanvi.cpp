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
int n,gt[N],dd[N],k,t;
vector<int>p;
void solve()
{
    p.clear();
    string line;
    getline(cin >> ws, line);
    stringstream ss(line);

    while(ss >> t) p.push_back(t);
    n=p.size();
    gt[0]=1;
    FOR(i,1,n)  gt[i]=gt[i-1]*i;
    int cnt=1;
    FOR(i,1,n)
    {
        dd[p[i-1]]=1;
        for(int x=1; x<p[i-1]; x++)    if(!dd[x])  cnt+=gt[n-i];

    }
    cout<<cnt<<'\n';
    FOR(i,1,n) dd[i] = 0;
    cin>>k;
    FOR(i,1,n)
    {
        FOR(x,1,n)
        {
            if(!dd[x])
            {
                if(gt[n-i]<k)   k-=gt[n-i];
                else
                {
                    cout<<x<<' ';
                    dd[x]=1;
                    break;
                }
            }
        }

    }
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
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
