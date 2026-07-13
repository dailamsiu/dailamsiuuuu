#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,a[305][305],dp[305][305][305];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>a[i][j];
        }
    }
   memset(dp,-0x3f,sizeof(dp));dp[1][1][1]=a[1][1];
    for(int x1=1;x1<=n;x1++)
    {
        for(int y1=1;y1<=n;y1++)
        {
            for(int x2=1;x2<=n;x2++)
            {
                int y2=x1+y1-x2;
                if(y2<1&&y2>n)continue;
                int pro=0;
                if(x1==x2)  pro=a[x1][y1];
                else    pro=a[x1][y1]+a[x2][y2];
                int mx=max({dp[x1-1][y1][x2-1],dp[x1-1][y1][x2],dp[x1][y1-1][x2-1],dp[x1][y1-1][x2]});
                dp[x1][y1][x2]=max(dp[x1][y1][x2],mx+pro);
            }
        }
    }
    cout<<dp[n][n][n];
}
