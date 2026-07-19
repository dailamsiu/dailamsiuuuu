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
int dist[N],q,n,x[N],y[N];
vector<int>px[N],py[N];
int calc(int x1,int y1,int x2,int y2)
{
    return abs(x1-x2)+abs(y1-y2);
}
int getpos(int px1,int py1)
{
    for(int id:px[px1])
    {
        if(calc(x[id],y[id],px1,py1)+calc(x[id+1],y[id+1],px1,py1)==calc(x[id],y[id],x[id+1],y[id+1]))
        {
                return dist[id]+calc(x[id],y[id],px1,py1);
        }
    }
    for(int id:py[py1])
    {
        if(calc(x[id],y[id],px1,py1)+calc(x[id+1],y[id+1],px1,py1)==calc(x[id],y[id],x[id+1],y[id+1]))
        {
                return dist[id]+calc(x[id],y[id],px1,py1);
        }
    }
    return -1;
}
void solve() {
    cin>>q>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        
    }
    x[n+1]=x[1];
    y[n+1]=y[1];
    for(int i=1;i<=n;i++)
    {
        dist[i+1]=dist[i]+calc(x[i],y[i],x[i+1],y[i+1]);
        if(x[i]==x[i+1])
        {
            px[x[i]].push_back(i);
        }
        if(y[i]==y[i+1])
        {
            py[y[i]].push_back(i);
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        int posa=getpos(x1,y1),posb=getpos(x2,y2);
        int distxuoi=max(posa,posb)-min(posa,posb),distnguoc=dist[n+1]-distxuoi;
        cout<<min(distxuoi,distnguoc)<<'\n';
    }
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
    cerr << "\n" << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
}