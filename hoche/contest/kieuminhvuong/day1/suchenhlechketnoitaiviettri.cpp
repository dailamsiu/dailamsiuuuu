#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int a[N],dd[N],n;
struct dsu
{
    vector<int>par,sz;
    dsu(int n)
    {
        par.resize(n+1);
        sz.resize(n+1);
        for(int i=1;i<=n;i++)   par[i]=i,sz[i]=1;
    }
    int find_(int v)
    {
        return (v==par[v]?v:par[v]=find_(par[v]));
    }
    int get(int v)
    {
        return sz[find_(v)];
    }
    void uni(int u,int v)
    {
        u=find_(u);v=find_(v);
        if(u!=v)
        {
            par[v]=u;
            sz[u]+=sz[v];
        }

    }
};
vector<int>g[N];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    vector<int>node(n);
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        node[i-1]=i;
    }
    for(int i=1;i<n;i++)
    {
        int u,v;cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int mx=0,mn=0;
    sort(node.begin(),node.end(),[](int x,int y)
        {
            return a[x]<a[y];
        });
    dsu dsumx(n);
    for(auto u:node)
    {
        dd[u]=1;
        for(int v:g[u])
        {
            if(dd[v])
            {
                if(dsumx.find_(u)!=dsumx.find_(v))
                {
                    mx+=a[u]*dsumx.get(u)*dsumx.get(v);
                    dsumx.uni(u,v);
                }
            }
        }
    }
    sort(node.begin(),node.end(),[](int x,int y)
        {
            return a[x]>a[y];
        });
    dsu dsumn(n);
    memset(dd,0,sizeof(dd));
    for(auto u:node)
    {
        dd[u]=1;
        for(int v:g[u])
        {
            if(dd[v])
            {
                if(dsumn.find_(u)!=dsumn.find_(v))
                {
                    mn+=a[u]*dsumn.get(u)*dsumn.get(v);
                    dsumn.uni(u,v);
                }
            }
        }
    }
    cout<<mx-mn;
}


