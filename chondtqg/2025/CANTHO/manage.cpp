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
int n,m,q,t[N],vis[N],pos[N],employ[N];
vector<int>g[N],mana[N];
void dfs(int u,int st)
{
    vis[u]=1;
    for(int v:g[u])
    {
        if(!vis[v])
        {
            mana[st].push_back(v);
            dfs(v,st);
        }
    }
}
void solve() {
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>t[i];
        pos[i]=i;
        employ[i]=i;
    }
    for(int i=1;i<=m;i++)
    {
        int x,y;cin>>x>>y;
        g[y].push_back(x);
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            vis[j]=0;
        }
        dfs(i,i);
    }
    while(q--)
    {
        int type;cin>>type;
        if(type==1)
        {
            int u,v;cin>>u>>v;
            int pu=pos[u],pv=pos[v];
            swap(pos[u],pos[v]);
            swap(employ[pu],employ[pv]);
        }
        else
        {
            int e;cin>>e;
            int p=pos[e];
            if(mana[p].empty())
            {
                cout<<0<<'\n';
            }
            else
            {
                int mn=1e18;
                for(int pos:mana[p])
                {
                    mn=min(mn,t[employ[pos]]);
                }
                cout<<mn<<'\n';
            }
            
        }
    }

}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}