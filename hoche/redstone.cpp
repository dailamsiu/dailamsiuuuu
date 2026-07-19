#include<bits/stdc++.h>
#define ll long long
using namespace std;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,-1,1};
int dist[505][505];
int n,m,Q,k;
void solve()
{
    cin>>n>>m>>k>>Q;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=m; j++)
        {
            dist[i][j] = -1;
        }
    }
    queue<pair<int,int>>q;
    int res =0;
    while(Q--)
    {
        int x,y;
        cin>>x>>y;
        if(k > dist[x][y])
        {
            if(dist[x][y] == -1) res++;
            dist[x][y] = k;
            q.push({x,y});
        }
        while(!q.empty())
        {
            int x1 = q.front().first;
            int y1 = q.front().second;
            q.pop();

            int rem = dist[x1][y1];
            if(rem==0) continue;


            for(int i=0; i<4; i++)
            {
                int nx = x1 + dx[i];
                int ny = y1 + dy[i];
                if(nx>=1 && nx<= n && ny >= 1 && ny<= m)
                    if(rem-1>dist[nx][ny])
                    {
                        if(dist[nx][ny] == -1) res++;
                        dist[nx][ny] = rem- 1;
                        q.push({nx,ny});
                    }
            }
        }
        cout<<res<<"\n";
    }
}
main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    solve();
}
