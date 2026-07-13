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
int rand(int l, int r) { assert(l <= r); return uniform_int_distribution<int>(l, r)(rd); }
const int N = 2e6 + 5;
const int mod = 998244353;
const int BASE = 3137;
const int BLSZ=448;
string s;
int lps[N];
void solve() {
    memset(lps,0,sizeof(lps));
    cin>>s;
    string c=s;
    reverse(c.begin(),c.end());
    string d=c+"#"+s;
    for(int i=1;i<d.size();i++)
    {
        int j=lps[i-1];
        while(j>0&&d[i]!=d[j])
        {
            j=lps[j-1];
        }
        if(d[i]==d[j])  j++;
        lps[i]=j;
    }
    cout<<s.size()+(s.size()-lps[d.size()-1])<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    for(int i=1;i<=ntest;i++)
    {
        cout<<"Case "<<i<<": ";solve();
    }
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}
