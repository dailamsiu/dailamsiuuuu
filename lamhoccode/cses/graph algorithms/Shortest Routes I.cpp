/// created day : today
#include <bits/stdc++.h>
#define fr(i,a,n) for(int i=a;i<=n;++i)
#define fx(i,b,a) for(int i=b;i>=a;--i)
#define ii pair<int,int>
#define fi first
#define se second
#define FILE "name"
using namespace std;
using ll = long long;
const int N = 1e5+7;
const int mod1 = 1e9+7;
const int mod2 = 1e9+9;
const ll inf = 1e18+7;
const int lg =21;
mt19937_64 Rand(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int l,int r){
    return uniform_int_distribution<int>(l,r)(Rand);
}
int n,m;
vector<ii>g[N];
void sol(){
    vector<int>dist(n+1,inf);
    dist[1]=0;
    priority_queue<ii,vector<ii>,greater<ii>>q;
    q.push({0LL,1LL});
    while(q.size())
    {
        auto [dicku,u]=q.top();q.pop();
        if(dicku!=dist[u])  continue;
        for(auto [v,w]:g[u])
        {
            if(dist[v]>dist[u]+w)
            {
                dist[v]=dist[u]+w;
                q.push({dist[v],v});
            }
        }
    }
    for(int i=1;i<=n;i++)   cout<<dist[i]<<' ';
}
void init_world(){
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int u,v,c;cin>>u>>v>>c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }
}
signed main(){
    if(fopen(FILE".inp","r")){
        freopen(FILE".inp","r",stdin);
        freopen(FILE".out","w",stdout);
    }
    init_world();
    sol();
    return 0;
}
