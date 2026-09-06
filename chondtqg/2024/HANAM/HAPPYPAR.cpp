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
const int mod = 998244353;
int binpow(int a,int b,int c)
{
    int res=1;
    while(b)
    {
        if(b&1) {res*=a;res%=c;}
        a*=a;a%=c;
    }
    return res;
}
int nghichdaomodulo(int a,int c)
{
    return binpow(a,c-2,c);
}
int n,m,a[N];
void solve() {
    cin>>n>>m;map<int,vector<int>>mp;
    for(int i=1;i<=n;i++)   
    {
        cin>>a[i];
        mp[a[i]].push_back(i);
    }
    int d=0;
    int nghichdao=nghichdaomodulo(2,mod);
    int pre=(n%mod*((n+1)%mod))%mod,prem=(m%mod*((m+1)%mod))%mod;
    pre=(pre%mod*nghichdao)%mod;
    prem=(prem%mod*nghichdao)%mod;
    int ans=(pre*prem)%mod;
    for(auto x:mp)
    {
        int nx=x.first%mod;
        vector<int>&res=x.second;
        vector<int>pos;
        pos.push_back(0);
        for(auto x:res)
        {
            pos.push_back(x);
        }
        pos.push_back(n+1);
        int cx=0;
        for(int i=0;i<pos.size()-1;i++)
        {
            int tmp=pos[i+1]-pos[i]-1;
            if(tmp>0)
            {
                int t=(tmp%mod*((tmp+1)%mod))%mod;
                t=(t%mod*nghichdao)%mod;
                cx=(cx+t)%mod;
            }
        }
        int doan=(pre-cx+mod)%mod;
        ans=(ans-((doan*nx)%mod)+mod)%mod;
    }
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}