#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1005;
int n,m,k,q,dist[N][N],d,x,y;
queue<pair<int,int>>qu;
int res=0;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
main()
{
    if(fopen("REDSTONE.inp","r"))
    {

    freopen("REDSTONE.inp","r",stdin);
    freopen("REDSTONE.out","w",stdout);
    }
    cin>>n>>m>>k>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dist[i][j]=-1;
        }
    }
    while(q--)
    {

        cin>>x>>y;
        if(dist[x][y]<k)
        {
            if(dist[x][y]==-1) res++;
            dist[x][y]=k;
            qu.push({x,y});
        }
        while(!qu.empty())
        {
            auto [u,v]=qu.front();
            qu.pop();
            if(dist[u][v]==0) continue;
            for(int i=0;i<4;i++)
            {
                int nx=u+dx[i];
                int ny=v+dy[i];
                if(nx>=1&&nx<=n&&ny>=1&&ny<=m)
                    if(dist[u][v]-1>dist[nx][ny])
                    {
                        if(dist[nx][ny] == -1) res++;
                        dist[nx][ny] = dist[u][v]- 1;
                        qu.push({nx,ny});
                    }
            }
        }
        cout<<res<<"\n";
    }
}

