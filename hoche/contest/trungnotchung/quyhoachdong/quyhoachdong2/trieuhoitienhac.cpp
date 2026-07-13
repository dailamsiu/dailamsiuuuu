#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,w,b,x,c[N],cost[N],f[1005][10005],t;
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>w>>b>>x;
    for(int i=1; i<=n; i++)cin>>c[i],t+=c[i];
    for(int i=1; i<=n; i++)cin>>cost[i];

    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=t; j++)    f[i][j]=-1;
    }f[0][0]=w;
    for(int i=1; i<=n; i++)
    {


        for(int cnt=0; cnt<=t; cnt++)
        {
            if(f[i-1][cnt]>=0)
            {
                f[i][cnt]=min(f[i-1][cnt]+x,w+b*cnt);///khong trieu hoi
            }
        }
        for(int cnt=t;cnt>=0;cnt--)
        {
            for(int j=1;j<=c[i]&&j<=cnt;j++)
            {
                if(f[i][cnt-j]>=0)
                {
                    if(f[i][cnt-j]>=j*cost[i])
                    {
                        f[i][cnt]=max(f[i][cnt],f[i][cnt-j]-j*cost[i]);
                    }
                }
            }
        }

    }
    int ans=0;
    for(int cnt=0; cnt<=t; cnt++) if(f[n][cnt]>=0)ans=cnt;
    cout<<ans;

}

