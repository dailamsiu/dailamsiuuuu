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
const int N = 1e3 + 5;
const int mod = 1e9+7;
int n,q,bit[N][N];
char a[N][N];
void upd(int x,int y,int val)
{
    for(int i=x;i<=n;i+=i&-i)
    {
        for(int j=y;j<=n;j+=j&-j)
        {
            bit[i][j]+=val;
        }
    }
}
int get(int x,int y)
{
    int res=0;
    for(int i=x;i>0;i-=i&-i)
    {
        for(int j=y;j>0;j-=j&-j)
        {
            res+=bit[i][j];
        }
    }
    return res;
}
int query(int x1,int y1,int x2,int y2)
{
    return get(x2,y2)-get(x1-1,y2)-get(x2,y1-1)+get(x1-1,y1-1);
}
void solve() {
    cin>>n>>q;
    for(int i=1;i<=n;i++)   
    {
        for(int j=1;j<=n;j++)   
        {
            cin>>a[i][j];
            if(a[i][j]=='*')    upd(i,j,1);
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2;cin>>x1>>y1>>x2>>y2;
        cout<<query(x1,y1,x2,y2)<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}