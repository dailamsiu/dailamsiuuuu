#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("inline")
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
const int N = 1e6 + 5;
const int mod = 1e9+7;
int b[N],n;
void solve() {
    cin>>n;
    int ok=1;
    vector<bool>mp(n+1,0);
    for(int i=1;i<=n/2;i++) 
    {
        cin>>b[i];
        if(mp[b[i]])    ok=0;
        mp[b[i]]=1;
    }
    if(!ok)
    {
        cout<<-1<<'\n';return;
    }
    set<int>d;
    for(int i=1;i<=n;i++)
    {
        if(!mp[i])  d.insert(i);
    }
    vector<int>p(n+1);
    for(int i=n/2;i>=1;i--)
    {
        auto it=d.lower_bound(b[i]);
        if(it==d.begin())
        {
            cout<<-1<<'\n';return;
        }
        it--;
        p[2*i-1]=*it;
        p[2*i]=b[i];d.erase(it);
    }
    for(int i=1;i<=n;i++)
    {
        cout<<p[i]<<' ';
    }
    cout<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
}