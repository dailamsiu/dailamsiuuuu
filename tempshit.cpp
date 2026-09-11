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
const int N = 1e7 + 5;
const int mod = 1e9+7;
int snt[N];
void sang()
{
    snt[0]=snt[1]=1;
    for(int i=2;i*i<N;i++)
    {
        if(!snt[i]) 
        for(int j=i*i;j<N;j+=i)
        {
            snt[j]=1;
        }
    }
}

bool check(int x)
{
    int right=0,d=1;if(snt[x]) return 0;
    while(x>9)
    {
        
        int nx=(x%10)*d+right;
        right=nx;
        x/=10;
        if(!snt[right]&&!snt[x])   return 1;
        d*=10;
    }
    return 0;
}
int f[N];
void pre()
{
    for(int i=1;i<N;i++)
    {
        f[i]+=f[i-1];
        if(check(i))    f[i]++;
    }
}
void solve() {
    int l,r;cin>>l>>r;
    cout<<f[r]-f[l-1]<<'\n';
}
dailamsiu() {sang();pre();
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; cin >> ntest;
    while (ntest--) solve();
}