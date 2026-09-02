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
int t,u,v,pre[N];
queue<int>q;
void solve() {
    pre[2]=1;
    q.push(2);
    while(!q.empty())
    {
        int x=q.front();q.pop();
        if(x>1e7)   break;
        int nx1=x*2+1;
        if(nx1<=1e7&&!pre[nx1])
        {
            pre[nx1]=1;
            q.push(nx1);
        }
        int nx2=x*3;
        if(nx2<=1e7&&!pre[nx2])
        {
            pre[nx2]=1;
            q.push(nx2);
        }
    }
    for(int i=1;i<N;i++)
    {
        pre[i]+=pre[i-1];
    }
    cin>>t;
    while(t--)
    {
        cin>>u>>v;
        cout<<pre[v]-pre[u-1]<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}