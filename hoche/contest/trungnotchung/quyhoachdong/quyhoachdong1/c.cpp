#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,a[N],b[N],dp[105][100005];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n;
    int s=0;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];s+=a[i];
    }
    int sumb=0;
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];sumb+=b[i];
    }
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=sumb;j++)    dp[i][j]=-1e18;
    }
    dp[0][0]=0;
    for(int i=1;i<=n;i++)
    {
        for(int cnt=i-1;cnt>=0;cnt--)
        {
            for(int v=sumb-b[i];v>=0;v--)
            {
                if(dp[cnt][v]==-1e18)continue;
                dp[cnt+1][v+b[i]]=max(dp[cnt+1][v+b[i]],dp[cnt][v]+a[i]);
            }
        }

    }
    int k=-1,t=-1;
    for(int cnt=1;cnt<=n;cnt++)
    {
        int mx=-1e18;
        for(int v=s;v<=sumb;v++)
        {
            mx=max(mx,dp[cnt][v]);
        }
        if(mx!=-1e18)
        {
            k=cnt;
            t=s-mx;
            break;
        }

    }
    cout<<k<<' '<<t;
}
