#include<bits/stdc++.h>
#define int long long
#define N 1005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,m,dist[3][N][N];
string grid[N];
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
void bfs(char c,int id)
{
    deque<pii>dq;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==c)
            {
                dist[id][i][j]=0;
                dq.push_back({i,j});
            }
        }
    }
    while(dq.size())
    {
        int x=dq.front().first,y=dq.front().second;
        dq.pop_front();
        for(int i=0;i<4;i++)
        {
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(nx>=0&&nx<n&&ny>=0&&ny<m&&grid[nx][ny]!='#')
            {
                int cost=(grid[nx][ny]=='.');
                if(dist[id][nx][ny]>dist[id][x][y]+cost)
                {
                    dist[id][nx][ny]=dist[id][x][y]+cost;
                    if(cost==1)
                    {
                        dq.push_back({nx,ny});
                    }
                    else
                    {
                        dq.push_front({nx,ny});
                    }
                }
            }
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
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        cin>>grid[i];
    }
    for(int i=0;i<3;i++)
    {
        for(int r=0;r<n;r++)
        {
            for(int c=0;c<m;c++)
            {
                dist[i][r][c]=1e18;
            }
        }
    }
    bfs('1',0);bfs('2',1);bfs('3',2);
    int ans=1e18;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(dist[0][i][j]!=1e18&&dist[1][i][j]!=1e18&&dist[2][i][j]!=1e18)
            {
                int cost=dist[1][i][j]+dist[0][i][j]+dist[2][i][j];
                if(grid[i][j]=='.')
                {
                    cost-=2;
                }
                ans=min(ans,cost);
            }
        }
    }
    cout<<(ans==1e18?-1:ans);
}
