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
const int base=31;
string s;int q,l,r,p[N],hl[N],hr[N];
int gethashl(int l,int r)
{
    return ((hl[r]-hl[l-1]*p[r-l+1])%mod+mod)%mod;
}
int gethashr(int l,int r)
{
    return ((hr[l]-hr[r+1]*p[r-l+1])%mod+mod)%mod;
}
void solve() {
    cin>>s;
    p[0]=1;
    for(int i=1;i<=s.size();i++)
    {
        p[i]=(p[i-1]*base)%mod;
        hl[i]=((hl[i-1]*base)+(s[i-1]-48))%mod;
        
    }
    for(int i=s.size();i>=1;i--)
    {
        hr[i]=((hr[i+1]*base)+(s[i-1]-48))%mod;
    }
    cin>>q;
    while(q--)
    {
        int l,r;cin>>l>>r;
        if(gethashl(l,r)==gethashr(l,r))
        {
            cout<<1;
        }
        else
        cout<<-1;
        cout<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}