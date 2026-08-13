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
int n,t;
struct nodea
{
    int v,id;
}a[N];
struct queries
{
    int k,i,j,id;
}q[N];
int bit[N],ans[N];
void upd(int pos)
{
    for(;pos<=N;pos+=pos&-pos)  bit[pos]++;
}
int get(int pos)
{
    int res=0;
    for(;pos>0;pos-=pos&-pos)   res+=bit[pos];
    return res;
}
int get(int l,int r)
{
    return get(r)-get(l-1);
}
void solve() {
    cin>>n;
    for(int i=1;i<=n;i++)   cin>>a[i].v,a[i].id=i;
    cin>>t;
    for(int x=1;x<=t;x++)   cin>>q[x].i>>q[x].j>>q[x].k,q[x].id=x;
    sort(q+1,q+t+1,[](queries x,queries y){
        return x.k>y.k;
    });
    sort(a+1,a+n+1,[](nodea x,nodea y){
        return x.v>y.v;
    });
    int ptr=1;
    for(int x=1;x<=t;x++)
    {
        while(ptr<=n&&a[ptr].v>q[x].k)
        {upd(a[ptr].id);
            ptr++;
            
        }
        ans[q[x].id]=get(q[x].i,q[x].j);
    }
    for(int i=1;i<=t;i++)   cout<<ans[i]<<'\n';
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}