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
int n,m,k,a[N],b[N];
struct node
{
    int val,idi,idj;
    bool operator>(const node &x)const
    {
        return val>x.val;
    }
};
void solve() {
    cin>>n>>m>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    priority_queue<node,vector<node>,greater<node>>q;
    sort(a+1,a+n+1);
    sort(b+1,b+m+1);
    for(int i=1;i<=n;i++)
    {
        q.push({a[i]+b[1],i,1});
    }
    int d=0;
    while(!q.empty()&&d<k)
    {
        auto [tong,i,j]=q.top();q.pop();
        cout<<tong<<'\n';
        if(j+1<=m)
        {
            q.push({a[i]+b[j+1],i,j+1});
        }
        d++;
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}