#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
const int mod=1e9;
int n,q,m;
vector<pii>g[N];
int par[N],depth[N],f[N],chain[N],pos[N],cnt,w[N];
pii a[N];
void dfs(int u,int p)
{
    par[u]=p;
    depth[u]=depth[p]+1;
    f[u]=1;
    for(auto [v,w]:g[u])
    {
        if(v==p)    continue;
        dfs(v,u);
        f[u]+=f[v];
    }
}
void build(int u,int ch)
{
    chain[u]=ch;
    pos[u]=++cnt;
    int nxt=-1,mx=0;
    for(auto [v,w]:g[u])
    {
        if(v==par[u])
        {
            continue;
        }
        if(mx<f[v])
        {
            mx=f[v];
            nxt=v;
        }
    }
    if(nxt!=-1) build(nxt,ch);
    for(auto [v,w]:g[u])
    {
        if(v!=par[u]&&v!=nxt)   build(v,v);
    }
}
int st[4*N];
void upd(int id,int l,int r,int i,int v)
{
    if(l>r||i<l||i>r) return;
    if(l==r&&l==i)
    {
        st[id]=v;
        return;
    }
    int mid=(l+r)/2;
    upd(id*2,l,mid,i,v);
    upd(id*2+1,mid+1,r,i,v);
    st[id]=(st[id*2]*st[id*2+1])%mod;
}
int get(int id,int l,int r,int u,int v)
{
    if(v<l||r<u)    return 1;
    if(u<=l&&r<=v)  return st[id];
    int mid=(l+r)/2;
    return (get(id*2,l,mid,u,v)*get(id*2+1,mid+1,r,u,v))%mod;
}
int calc(int u,int v)
{
    int res=1;
    while(chain[u]!=chain[v])
    {
        if(depth[chain[u]]>depth[chain[v]])
        {
            res=(res*get(1,1,m,pos[chain[u]],pos[u]))%mod;
            u=par[chain[u]];
        }
        else
        {
            res=(res*get(1,1,m,pos[chain[v]],pos[v]))%mod;
            v=par[chain[v]];
        }
    }
    if(pos[u]>pos[v])   swap(u,v);
    res=(res*get(1,1,m,pos[u]+1,pos[v]))%mod;
    return res;
}
main()
{
    fill(st, st + 4 * n + 5, 1);
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>q;
    m=1;
    while(m<n)  m*=2;
    for(int i=1; i<n; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
        w[i]=c;
        a[i]= {u,v};
    }
    dfs(1,0);
    build(1,1);
    for(int i=1; i<=m; i++)
    {
        auto [u,v]=a[i];
        int c=w[i];
        if(depth[u]<depth[v])
        {
            swap(u,v);
            swap(a[i].first,a[i].second);
        }
        upd(1,1,m,pos[u],c);
    }
    while(q--)
    {
        int t,u,v;
        cin>>t>>u>>v;
        if(t==1)
        {
            upd(1,1,m,pos[a[u].first],v);
        }
        else
        {
            cout<<calc(u,v)<<'\n';
        }
    }
}
