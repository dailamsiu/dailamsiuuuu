#include<bits/stdc++.h>
#define int long long
#define N 1000005
#define pii pair<int,int>
#define ten "cau"
using namespace std;
int n,q,v[N],c[N],dp[N],g[N];
main()
{
    if(fopen(ten".inp","r"))
    {
        freopen(ten".inp","r",stdin);
        freopen(ten".out","w",stdout);
    }
    cin>>n>>q;
    for(int i=1; i<=n; i++)   cin>>v[i];
    for(int i=1; i<=n; i++)   cin>>c[i];
    while(q--)
    {
        int a,b;
        cin>>a>>b;
        for(int i=1; i<=n; i++)
        {
            g[i]=-1e18;}
            int id=-1,mx1=-1,mx2=-1,ans=0;
            for(int i=1; i<=n; i++)
            {
                dp[i]=b*v[i];
                if(g[c[i]]!=-1e18)
                {
                    dp[i]=max(dp[i],g[c[i]]+a*v[i]);
                }
                if(id!=c[i])
                {
                    if(mx1!=-1e18)  dp[i]=max(dp[i],mx1+v[i]*b);
                }
                else
                {
                    if(mx2!=-1e18)
                    {
                        dp[i]=max(dp[i],mx2+v[i]*b);
                    }
                }
                ans=max(ans,dp[i]);
                if(c[i]==id)
                    mx1=max(mx1,dp[i]);
                else
                {
                    if(dp[i]>mx1)
                    {
                        mx2=mx1;
                        mx1=dp[i];
                        id=c[i];
                    }
                    else    mx2=max(mx2,dp[i]);
                }
                g[c[i]]=max(g[c[i]],dp[i]);
            }
cout<<ans<<'\n';
        }

    }


