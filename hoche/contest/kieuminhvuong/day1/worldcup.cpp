    #include<bits/stdc++.h>
    #define int long long
    #define N 1000005
    #define pii pair<int,int>
    #define ten "cau"
    using namespace std;
    int par[N];
    struct node
    {
        int u,v,w,id;
        bool operator<(const node& o)const
        {
            if(w!=o.w)  return w<o.w;
            return id<o.id;
        }
    };
    int find_(int v)
    {
        return (v==par[v]?v:par[v]=find_(par[v]));
    }
    bool uni(int u,int v)
    {
        u=find_(u);
        v=find_(v);
        if(u==v)    return 0;
        par[v]=u;
        return 1;
    }
    int m,n;
    vector<node>e;
    vector<vector<pii>>g(N+1);
    vector<int>vis(N+1),order;
    void dfs(int u)
    {
        vis[u]=1;
        for(auto edge:g[u])
        {
            int v=edge.first,i=edge.second;
            if(!vis[v])
            {
                order.push_back(i);dfs(v);
            }
        }
    }
    main()
    {
        if(fopen(ten".inp","r"))
        {
            freopen(ten".inp","r",stdin);
            freopen(ten".out","w",stdout);
        }
        cin>>m>>n;
        for(int i=1;i<=m;i++)
        {
            int u,v,w;cin>>u>>v>>w;
            e.push_back({u,v,w,i});
        }
        for(int i=1;i<=n;i++)   par[i]=i;
        sort(e.begin(),e.end());
             int t=0;
             vector<pii>res;
        for(auto x:e)
        {
            if(!uni(x.u,x.v))
            {
                continue;
            }
            g[x.u].push_back({x.v,x.id});
            g[x.v].push_back({x.u,x.id});
        }
        dfs(1);
        cout<<order.size()<<'\n';
        for(auto x:order)   cout<<x<<' ';



    }
