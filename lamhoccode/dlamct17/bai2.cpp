#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "bai2"
using namespace std;
int n,m,a[N],dp[N],f[N];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        f[i]=f[i-1]+a[i];
    }
    fill(dp+1,dp+n+1,1e18);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        {
            if(f[i]-f[j-1]<=m)
            {
                dp[i]=min(dp[i],dp[j-1]+1);
            }
        }
    }
    cout<<dp[n];
}
