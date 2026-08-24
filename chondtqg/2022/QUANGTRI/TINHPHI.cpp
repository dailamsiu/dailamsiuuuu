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
int n,m,k,s,t;
vector<pii>g[N];
struct node
{
    int dist,u,k;
    bool operator>(const node& o)const
    {
        return dist>o.dist;
    }
};
void solve() {
    cin>>n>>m>>k>>s>>t;
    for(int i=1;i<=m;i++)
    {
        int u,v,w;cin>>u>>v>>w;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }  
    priority_queue<node,vector<node>,greater<node>>q;
    q.push({0LL,s,k});
    vector<vector<int>>len(n+1,vector<int>(k+1,1e18));
    len[s][k]=0;
    while(!q.empty())
    {
        auto x=q.top();q.pop();
        int o=x.dist,ou=x.u,ok=x.k;
        if(o!=len[ou][ok]) continue;
        for(auto [v,w]:g[ou])
        {
            if(len[v][ok]>len[ou][ok]+w)
            {
                len[v][ok]=len[ou][ok]+w;
                q.push({len[v][ok],v,ok});
            }
            if(ok>=1)
            {
                if(len[v][ok-1]>len[ou][ok])
                {
                    len[v][ok-1]=len[ou][ok];
                    q.push({len[v][ok-1],v,ok-1});
                }
            }
        }
    }
    int ans=1e18;
    for(int i=0;i<=k;i++)
    {
ans=min(ans,len[t][i]);
    }
    cout<<ans;
}
dailamsiu() {
    if (fopen(task".inp", "r")) { freopen(task".inp", "r", stdin); freopen(task".out", "w", stdout); }
    ios::sync_with_stdio(0); cin.tie(0);
    int ntest = 1; //cin >> ntest;
    while (ntest--) solve();
}