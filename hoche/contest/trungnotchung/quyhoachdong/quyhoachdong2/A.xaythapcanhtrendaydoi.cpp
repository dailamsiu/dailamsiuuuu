#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,h[N],f[5005][5005],g[5005][5005];
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
        cin>>h[i];
    }

    for(int i=0;i<=n+1;i++)
    {
        for(int j=0;j<=(n+1)/2;j++)
        {
            f[i][j]=g[i][j]=1e18;
        }
    }
    for(int i=1;i<=n;i++)
    {
        int cur=0;
        if(i>1)
            cur+=max(0LL,h[i-1]-h[i]+1);
        if(i<n)
            cur+=max(0LL,h[i+1]-h[i]+1);
        f[i][1]=cur;
    }
    for(int i=1;i<=n;i++)
    {
        g[i][1]=f[i][1];
        if(i>1) g[i][1]=min(g[i][1],g[i-1][1]);
    }
    for(int k=2;k<=(n+1)/2;k++)
    {
        for(int i=1;i<=n;i++)
        {
            if(i>=3&&g[i-3][k-1]!=1e18)
            {
                f[i][k]=min(f[i][k],g[i-3][k-1]+max(0LL,h[i-1]-h[i]+1)+max(0LL,h[i+1]-h[i]+1));
            }
            if(i>=2&&f[i-2][k-1]!=1e18)
            {
                int t1=max(0LL,min(h[i-1],h[i-2]-1)-h[i]+1),t2=max(0LL,h[i+1]-h[i]+1);
                f[i][k]=min(f[i][k],f[i-2][k-1]+t1+t2);
            }
        }
        for(int i=1;i<=n;i++)
        {
            g[i][k]=f[i][k];
            if(i>1) g[i][k]=min(g[i][k],g[i-1][k]);
        }
    }
    for(int k=1;k<=(n+1)/2;k++)
    {
        int ans=LLONG_MAX;
        for(int i=1;i<=n;i++)
        {
            ans=min(ans,f[i][k]);
        }
        cout<<ans<<' ';
    }


}
